import numpy as np
import cv2
import matplotlib.pyplot as plt
from matplotlib.gridspec import GridSpec
from matplotlib.patches import Rectangle
from matplotlib.widgets import Button

# --- 1. Load and preprocess image ---
img = cv2.imread('sample_images/airplane/airplane_2.png')
if img is None:
    raise FileNotFoundError("Could not load image. Check path.")

img = cv2.resize(img, (32, 32))
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB).astype(np.float32) / 255.0
img_chw = img_rgb.transpose(2, 0, 1)  # CHW (3, 32, 32)

# --- 2. Load weights ---
kernel = np.loadtxt('weights_txt/layer_0_kernel.txt').reshape(64, 3, 3, 3).transpose(0, 3, 1, 2)
bias = np.loadtxt('weights_txt/layer_0_bias.txt')

# --- 3. Compute feature maps ---
conv_maps = np.array([
    sum(cv2.filter2D(img_chw[c], -1, kernel[i][c]) for c in range(3))
    for i in range(64)
])
bias_maps = conv_maps + bias[:, None, None]
relu_maps = np.maximum(bias_maps, 0)

vmax_conv = np.max(np.abs(conv_maps), axis=(1, 2))
vmax_bias = np.max(np.abs(bias_maps), axis=(1, 2))

# --- 4. Display stages ---
display_stages = ['original', 'rgb_channels', 'conv', 'bias', 'relu']
current_idx = 0
fig = plt.figure(figsize=(12, 12))
fig.subplots_adjust(bottom=0.05, top=0.92)

patches = []
axes_flat = []

def clear_previous():
    global patches, axes_flat
    patches = []
    axes_flat = []

def plot_stage(stage):
    fig.clf()
    clear_previous()
    fig.suptitle('', fontsize=16)

    if stage == 'original':
        fig.suptitle('Original Image', fontsize=16)
        ax = fig.add_subplot(1, 1, 1)
        ax.imshow(img_rgb)
        ax.set_xticks([])
        ax.set_yticks([])
        axes_flat.append(ax)

    elif stage == 'rgb_channels':
        fig.suptitle('RGB Channels', fontsize=16)
        titles = ['Red', 'Green', 'Blue']
        cmaps = ['Reds', 'Greens', 'Blues']
        for i in range(3):
            ax = fig.add_subplot(1, 3, i+1)
            ax.imshow(img_chw[i], cmap=cmaps[i])
            ax.set_title(titles[i])
            ax.set_xticks([])
            ax.set_yticks([])
            rect = Rectangle((0, 0), 1, 1, transform=ax.transAxes,
                             fill=False, edgecolor='black', linewidth=1)
            ax.add_patch(rect)
            patches.append(rect)
            axes_flat.append(ax)

    else:
        stage_info = {
            'conv': {'maps': conv_maps, 'title': 'Conv1', 'cmap': 'seismic', 'vmaxs': vmax_conv},
            'bias': {'maps': bias_maps, 'title': 'Bias1', 'cmap': 'seismic', 'vmaxs': vmax_bias},
            'relu': {'maps': relu_maps, 'title': 'ReLU1', 'cmap': 'gray', 'vmaxs': None}
        }
        maps = stage_info[stage]['maps']
        title = stage_info[stage]['title']
        cmap = stage_info[stage]['cmap']
        vmaxs = stage_info[stage]['vmaxs']

        fig.suptitle(title, fontsize=16)
        gs = GridSpec(8, 8, figure=fig)
        for i in range(64):
            ax = fig.add_subplot(gs[i // 8, i % 8])
            v = vmaxs[i] if (vmaxs is not None) else None
            ax.imshow(maps[i], cmap=cmap, vmin=-v if v else None, vmax=v)
            ax.set_xticks([])
            ax.set_yticks([])
            rect = Rectangle((0, 0), 1, 1, transform=ax.transAxes,
                             fill=False, edgecolor='black', linewidth=1)
            ax.add_patch(rect)
            patches.append(rect)
            axes_flat.append(ax)

    fig.canvas.draw_idle()

def on_hover(event):
    if not axes_flat or not patches: return
    for idx, ax in enumerate(axes_flat):
        if event.inaxes == ax:
            patches[idx].set_edgecolor('red')
            patches[idx].set_linewidth(2)
        else:
            patches[idx].set_edgecolor('black')
            patches[idx].set_linewidth(1)
    fig.canvas.draw_idle()

def show_detailed_view(stage, index):
    detailed_fig, detailed_ax = plt.subplots(figsize=(6, 6))

    if stage == 'rgb_channels':
        titles = ['Red', 'Green', 'Blue']
        cmaps = ['Reds', 'Greens', 'Blues']
        detailed_ax.imshow(img_chw[index], cmap=cmaps[index])
        detailed_ax.set_title(f"{titles[index]} Channel")
    else:
        stage_info = {
            'conv': {'maps': conv_maps, 'title': 'Conv1', 'cmap': 'seismic', 'vmaxs': vmax_conv},
            'bias': {'maps': bias_maps, 'title': 'Bias1', 'cmap': 'seismic', 'vmaxs': vmax_bias},
            'relu': {'maps': relu_maps, 'title': 'ReLU1', 'cmap': 'gray', 'vmaxs': None}
        }
        maps = stage_info[stage]['maps']
        cmap = stage_info[stage]['cmap']
        vmaxs = stage_info[stage]['vmaxs']
        v = vmaxs[index] if vmaxs is not None else None
        detailed_ax.imshow(maps[index], cmap=cmap, vmin=-v if v else None, vmax=v)
        detailed_ax.set_title(f"{stage_info[stage]['title']} Feature Map {index}")

    detailed_ax.axis('off')
    btn_ax = detailed_fig.add_axes([0.8, 0.01, 0.15, 0.05])
    btn = Button(btn_ax, 'Close')

    def close(event):
        plt.close(detailed_fig)

    btn.on_clicked(close)
    plt.show()

def on_click(event):
    stage = display_stages[current_idx]
    if stage not in ['rgb_channels', 'conv', 'bias', 'relu']:
        return
    for idx, ax in enumerate(axes_flat):
        if event.inaxes == ax and event.dblclick:
            show_detailed_view(stage, idx)
            break

def on_key(event):
    global current_idx
    if event.key == 'right' and current_idx < len(display_stages) - 1:
        current_idx += 1
        plot_stage(display_stages[current_idx])
    elif event.key == 'left' and current_idx > 0:
        current_idx -= 1
        plot_stage(display_stages[current_idx])

# --- Bind Events ---
fig.canvas.mpl_connect('key_press_event', on_key)
fig.canvas.mpl_connect('motion_notify_event', on_hover)
fig.canvas.mpl_connect('button_press_event', on_click)

# --- Initial Display ---
plot_stage(display_stages[current_idx])
plt.show()

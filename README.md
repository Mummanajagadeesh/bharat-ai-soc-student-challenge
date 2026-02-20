# Problem Statement 5

## Real-Time Object Detection Using Hardware-Accelerated CNN on Xilinx Zynq FPGA with Arm Processor

### SUBMISSION VIDEO : 

<p align="center">
  <a href="https://youtu.be/FXMh82mkGck">
    <img src="https://img.youtube.com/vi/FXMh82mkGck/0.jpg" alt="Demo Video">
  </a>
</p>


## Objective
Design and implement a hardware-accelerated CNN inference system on a Xilinx Zynq SoC, leveraging FPGA fabric to achieve real-time object detection or image classification, and quantitatively demonstrate performance improvements over a CPU-only implementation.

## Project Description
This project focuses on accelerating edge AI workloads on embedded platforms using hardware/software co-design. Students will implement a lightweight convolutional neural network (CNN) for object detection or image classification on a Xilinx Zynq SoC, which integrates an Arm processor with FPGA fabric.

The system partitions functionality between the Arm core and FPGA:

- The Arm core handles image capture, preprocessing, control logic, and post-processing.
- The FPGA fabric accelerates compute-intensive CNN operations such as convolution, activation, and pooling using Vitis HLS or Vivado.

The final system will perform real-time inference using either a live camera feed or a standard dataset, with detailed performance comparison against a software-only CPU implementation.

<p align="center">
  <a href="https://youtu.be/_ufBkxl1zxo">
    <img src="https://img.youtube.com/vi/_ufBkxl1zxo/0.jpg" alt="Demo Video">
  </a>
</p>

## Key Requirements

### Hardware:
- Xilinx Zynq-based development board  
  - Examples: Zynq-7000, ZCU104, ZedBoard
- Camera input (USB or onboard) or stored image dataset
- Display output or serial console for results

### Software:

#### CNN Models:
- Lightweight models such as Tiny-YOLO, MobileNet, or a custom 3-layer CNN

#### FPGA Design:
- Vitis HLS or Vivado for CNN accelerator implementation
- Verilog or HLS C++ for hardware modules

#### Embedded Software:
- Vitis / SDSoC for HW/SW co-design
- Optional PetaLinux
- OpenCV for image capture and preprocessing
- C++ or Python for control logic and system integration

## Performance Targets
- Real-time or near real-time inference on embedded hardware
- Minimum 2× speedup compared to software-only CNN execution on Arm CPU
- Measurable improvements in:
  - Latency
  - Throughput
  - Power efficiency
- Efficient use of FPGA resources (LUTs, BRAM, DSPs)

## Deliverables
- Working FPGA-accelerated CNN prototype performing object detection or image classification
- Hardware/software co-design implementation running on a Zynq platform
- Performance comparison between:
  - CPU-only implementation
  - Hardware-accelerated implementation
- Documentation covering:
  - System architecture
  - Design partitioning decisions
  - Performance analysis (latency, throughput, resource usage, power)
- Live demo or recorded demonstration of real-time inference

## Learning Outcomes
- Understanding of embedded edge AI and CNN inference pipelines
- Practical experience with FPGA-based acceleration using HLS
- Skills in Arm–FPGA hardware/software co-design
- Performance analysis and optimization of embedded systems
- Insight into trade-offs between flexibility, performance, and power in heterogeneous SoCs

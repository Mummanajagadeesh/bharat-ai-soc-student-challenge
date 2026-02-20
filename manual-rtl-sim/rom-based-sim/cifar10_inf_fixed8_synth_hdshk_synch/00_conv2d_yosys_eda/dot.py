from graphviz import Source

# Path to your dot file
dot_path = ".yosys_show.dot"

# Load the dot file
with open(dot_path, "r") as f:
    dot_source = f.read()

# Render it as an SVG (or PNG, PDF, etc.)
graph = Source(dot_source)
graph.render("circuit", format="svg", cleanup=True)

print("Rendered graph saved as circuit.svg")

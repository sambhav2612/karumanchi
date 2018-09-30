class graph {
	constructor(vertices) {
		this.vertices = vertices;
		this.list = new Map();
	}
	addVertex(v) {
		this.list.set(v, []);
	}
	addEdge(v, w) {
		this.list.get(v).push(w);
		this.list.get(w).push(v);
	}
	print() {
		var keys = this.list.keys();
		for (var i of keys) {
			var values = this.list.get(i);
			var conc = "";
			for (var j of values)
				conc += j + " ";
			console.log(i + " -> " + conc);
		}
	}
}

var newGraph = new graph(6);
var vertices = ['A', 'B', 'C', 'D', 'E', 'F'];

// adding vertices 
for (var i = 0; i < vertices.length; i++)
	newGraph.addVertex(vertices[i]);

newGraph.addEdge('A', 'B');
newGraph.addEdge('B', 'C');
newGraph.addEdge('A', 'E');
newGraph.addEdge('C', 'E');
newGraph.addEdge('C', 'F');
newGraph.addEdge('E', 'F');
newGraph.addEdge('D', 'E');
newGraph.addEdge('A', 'D');

newGraph.print();

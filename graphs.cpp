#include <iostream>
#include <vector> // like a dynamic array

class simpleGraphNode 
{
public:
	simpleGraphNode(char c) : name(c) {} // set the 'name' field with the value
								         // equivalent to:
										 // simpleGraphNode(char c) { name = c; }
	char name;
};

class simpleGraphEdge
{
public:
	simpleGraphEdge(simpleGraphNode &x, simpleGraphNode &y) : a(x), b(y) {}
	simpleGraphNode &a;
	simpleGraphNode &b;
};

void introSimpleGraphs()
{
/*
Graphs
======
	- a collection of 'nodes' and 'edges'
nodes 
=====
	- data
edges
=====
	- link nodes together
	- always connects at least two pieces of data together
	- types of edges:
		--> non-directed
			- think of them as lines connecting nodes
				no relationship or dynamic implied
		--> directed
			- think of them as arrows pointing from 
				one node to another (ex: one way street)
cycle
=====
	- the ability to traverse a set of nodes back to itself
	--> acyclic = no cycles
	--> cyclic = cycles

How are graphs used?
===================
- map (streets, intersections, etc)
- a network of:
	- friends (facebook, google plus, etc)
	::
		Bob -> Joe, Sam, Sue
		Sam -> Sue [Bob]
		Joe -> [Bob]
*/

	// let's implement a simple graph:
	std::vector<simpleGraphEdge *> graph;

	// nodes:
	simpleGraphNode a('A');
	simpleGraphNode b('B');
	simpleGraphNode c('C');
	simpleGraphNode d('D');

	// edges:
	simpleGraphEdge ab(a,b);
	simpleGraphEdge ac(a,c);
	simpleGraphEdge ad(a,d);
	simpleGraphEdge bc(b,c);

	graph.push_back(&ab);
	graph.push_back(&ac);
	graph.push_back(&ad);
	graph.push_back(&bc);

	// let's print graphs!
	// create an iterator to see relationships:
	// (so vector returns the next value)
	std::vector<simpleGraphEdge *>::iterator it; 
	for (it = graph.begin(); it !=graph.end(); it++) // it++ has some operator overloading
	{
		simpleGraphEdge *ptr = *it; // de-reference a pointer to get a pointer?
		std::cout << "edge: " << ptr->a.name << " - " << ptr->b.name << std::endl;
	}
}
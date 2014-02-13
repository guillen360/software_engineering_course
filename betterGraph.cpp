#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

// *************************
// SCOPE MY GRAPH DATA TYPE
// *************************
class graph 
{
public:
		typedef char node;

protected:
	struct edge
	{
		edge(node t, int w) : target(t), weight(w) {} // a handy-dandy struct constructor!
		node target;
		int weight;
	};
	typedef std::map< node, std::vector<edge*> > edge_map;

	struct distance_finder
	{
		distance_finder(std::map<node, int> d) : dist(d) {}
		std::map<node, int> dist;

		bool operator() (node a, node b) { return dist[a] < dist[b]; }
	};

protected:
	edge_map adjacency_list;

public:
	graph() {}
	virtual ~graph() 
	{
		for (edge_map::iterator it = adjacency_list.begin(); it != adjacency_list.end(); it++)
		{
			for (std::vector<edge*>::iterator edge_it = it->second.begin(); edge_it != it->second.end(); edge_it++)
			{
				delete *edge_it;
			}
		}
	}

	void print() const; // you can't call any non-constant function on a 
						// constant type, so we're making this function
						// more accessible by making it a const
	void add_edge(node source, node target, int weight);
	std::vector<node> shortest_path(node start, node end, int *weight = NULL) const; // dijkstra's algorithm
};

// *****************************
// IMPLEMENT MY GRAPH DATA TYPE
// *****************************

void graph::print() const
{
	for (edge_map::const_iterator it = adjacency_list.begin(); it != adjacency_list.end(); it++)
	{
		std::cout << "[" << it->first << "] --> ";
		for (std::vector<edge*>::const_iterator edge_it = it->second.begin(); edge_it != it->second.end(); edge_it++)
		{
			std::cout << (*edge_it)->target << " (" << (*edge_it)->weight << "), ";
		}
		std::cout << std::endl;
	}
}

void graph::add_edge(char source, char target, int weight)
{
	// TODO: check if edge already exists..

	edge *e = new edge(target, weight);
	adjacency_list[source].push_back(e); // the way maps work, [source] will 
										 // will be added to the table
	//adjacency_list[target];	 // we need to make sure target node is added too

	// could also point back (but wouldn't be a "directive" graph, instead be "non-directive"):
	adjacency_list[target].push_back(new edge(source, weight));
}

std::vector<graph::node> graph::shortest_path(node start, node end, int *weight) const // *weight is an optional param
{
/*
Dikkstra's Algorithm (ie shortest path algorithm)
====================
(https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
this algorithm solves the problem of figuring out
the shortest path in a graph:

pseudocode:
==========
 1  function Dijkstra(Graph, source):
 2      for each vertex v in Graph:                                // Initializations
 3          dist[v] := infinity ;                                  // Unknown distance function from 
 4                                                                 // source to v
 5          previous[v] := undefined ;                             // Previous node in optimal path
 6      end for                                                    // from source
 7      
 8      dist[source] := 0 ;                                        // Distance from source to source
 9      Q := the set of all nodes in Graph ;                       // All nodes in the graph are
10                                                                 // unoptimized - thus are in Q
11      while Q is not empty:                                      // The main loop
12          u := vertex in Q with smallest distance in dist[] ;    // Source node in first case
13          remove u from Q ;
14          if dist[u] = infinity:
15              break ;                                            // all remaining vertices are
16          end if                                                 // inaccessible from source
17          
18          for each neighbor v of u:                              // where v has not yet been 
19                                                                 // removed from Q.
20              alt := dist[u] + dist_between(u, v) ;
21              if alt < dist[v]:                                  // Relax (u,v,a)
22                  dist[v] := alt ;
23                  previous[v] := u ;
24                  decrease-key v in Q;                           // Reorder v in the Queue
25              end if
26          end for
27      end while
28  return dist;
*/
	// data types:
	std::map<node, int> dist;
	std::map<node, node> previous;
	std::set<node> nodes;
	int INFINITY = std::numeric_limits<int>::max(); // this will represent infinity

	// init data:
	for (edge_map::const_iterator n = adjacency_list.begin(); n != adjacency_list.end(); n++)
	{
		dist[n->first] = INFINITY; 
		previous[n->first];
		nodes.insert(n->first);
	}
	// set source distance:
	dist[start] = 0;

	// loop through Qs:
	while (!nodes.empty())
	{
		// find node with smallest weight (node u):
		node u = *std::min_element(nodes.begin(), nodes.end(), distance_finder(dist)); // return pointer to the node

		// terminator: if node u INFINITY, break:
		if (dist[u] == INFINITY)
			break;
		if (u == end)
			break;

		// remove node u:
		nodes.erase(u);

		// visit all edges of node u finding smallest weight:
		const std::vector<edge*> edges = adjacency_list.find(u)->second; // use find instead of [] to not create the key on map
		for (std::vector<edge*>::const_iterator it = edges.begin(); it != edges.end(); ++it)
		{
			node v = (*it)->target;
			if (nodes.find(v) == nodes.end())
			{
				continue;
			}
			int d = dist[u] + (*it)->weight;
			if (d < dist[v])
			{
				dist[v] = d;
				previous[v] = u;
			}
		}
	}

	// all done building the map data structures, return a path value:
	std::vector<node> path;
	for (node n = end; n != start; )
	{
		path.push_back(n);
		n = previous[n];
	}
	path.push_back(start);

	if (weight != NULL)
	{
		*weight = dist[end];
	}

	return path;
}
// *****************************
// *** MAIN **
// *****************************

void betterGraph()
{
	graph g;
	g.add_edge('A', 'B', 1);
	g.add_edge('B', 'C', 2);
	g.add_edge('C', 'D', 4);
	g.add_edge('B', 'D', 5);
	g.add_edge('A', 'D', 10);

	g.print();
	int weight = std::numeric_limits<int>::max();
	std::vector<graph::node> path = g.shortest_path('A', 'D', &weight);

	for (std::vector<graph::node>::reverse_iterator it = path.rbegin(); it != path.rend(); ++it )
	{
		std::cout << *it;
		if (it + 1 != path.rend())
		{
			std::cout << " -> ";
		}
	}
	if (weight != std::numeric_limits<int>::max())
	{
		std::cout << " (" << weight << ")";
	}
	std::cout << std::endl;
}
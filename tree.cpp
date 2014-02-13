#include <iostream>
#include "ExpressionTree.h"
/*
Trees
=====
- trees are just graphs with 'Parent' node and 'Child' node
	- note: a node can be a parent and a child
Root:
- the top node(s)
Leaf:
- the bottom nodes

1. no cycles (cycle: A->B-C->A)
2. every node can have 0 or 1 parents

What do you use trees for?
- OS GUI:
	- a layer of items on the desktop
- game modeling:
	- you parent a joint to other child joints/limbs to they move together
- math:
	- expressions:
		1 + 2 x 3
		-- the operator is the parent node with the values the child nodes

==========
objective:
==========
- create a binary tree (every parent has at least 2 nodes) for expressions ("binary expression tree"?)
- in this lesson, we will build a tree of math expressions
- we will balance the tree by putting greater than node numbers on right and less than node on left
- will be using recursive patterns

implementation notes:
====================
1) leverage a stack to adhere to correct order of operations:
	- operator stack
	- operand stack (left side of tree... can be a value or an expression)
2) pop stack to build expression tree
3) evaluate tree to perform calculation
*/
/*
****************************my initial implementation:
class tree {
public:
	tree() {}
	~tree();
	struct node {
		node(char t, char o,int v): type(t), oper(o), value(v) {} 
	char type; // 'O' or 'I'
	char oper; // '*', '+', '-', '/'
	int value;
	};
	node* add_node(char t, char o, int v)
	{
		node *p = &node(t,o,v);
		return p;
	};
};
*/
void tree__main()
{
/*
****************************my initial implementation:
	std::cout << "hello trees" << std::endl;
	tree t;
	tree::node *a = t.add_node('O', '*', 0);
	tree::node *b = t.add_node('O', '+', 0);
	tree::node *c = t.add_node('I', '\0', 2);
	tree::node *d = t.add_node('I', '\0', 3);
	tree::node *e = t.add_node('I', '\0', 3);

	t.add_exp(*a, *c, *d);
	t.add_exp(*b, *d, *e);

	t.calc_result();
*/
	ExpressionTree exp("(1 + 2) * 4 / 2");
	std::cout << exp.Expression() << " = " << exp.Evaluate() << std::endl;

	ExpressionTree exp2("1.25 * 4");
	std::cout << exp2.Expression() << " = " << exp2.Evaluate() << std::endl;
}
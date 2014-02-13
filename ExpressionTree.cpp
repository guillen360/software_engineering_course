#include "ExpressionTree.h"
#include <stack>
#include <map>
#include <string>
#include <sstream>

ExpressionTree::operator_map ExpressionTree::operators; // ??? the operator_map is a map i created inside by class

ExpressionTree::ExpressionTree(const std::string &str) : expression(str) 
{
	if (operators.empty())
	{
		operators["+"] = OperatorInfo(0, Add);
		operators["-"] = OperatorInfo(0, Subtract);
		operators["*"] = OperatorInfo(1, Multiply);
		operators["/"] = OperatorInfo(1, Divide);
		operators["("] = OperatorInfo(-1, NULL);
		operators[")"] = OperatorInfo(-1, NULL);
		operators["#"] = OperatorInfo(-1, NULL); // bottom of operator stack
	}
	FromString(str);
}
void DeleteTree(ExpressionTree::Node *node)
{
	if (node == NULL) return;
	
	DeleteTree(node->Left);
	DeleteTree(node->Right);
	
	delete node;
}
ExpressionTree::~ExpressionTree()
{
	DeleteTree(root);
}

double ExpressionTree::Evaluate(ExpressionTree::Node *node) const
{
	if (node == NULL)
	{
		node = root;
	}
	
	// is the node an operator?  then evaluate left and right side of tree:
	operator_map::iterator it = operators.find(node->Value);
	if (it != operators.end())
	{
		return (it->second.Func)(Evaluate(node->Left), Evaluate(node->Right));
	}

	// the node is not an operator but an operand, just return value:
	std::istringstream ss(node->Value);
	double val;
	ss >> val;
	return val;
}
std::string ExpressionTree::Expression() const
{
	return ExpressionTree::expression;
}
void AddWhiteSpace(int idx, int insert_at, std::string &str)
{
	if (idx >= 0 && insert_at >= 0 && idx < str.length() && insert_at < str.length() && str[idx] != ' ')
		str.insert(insert_at, 1, ' ');
}
void PopOperator(std::stack<std::string> &operatorStack, std::stack<ExpressionTree::Node*> &operandStack)
{
	ExpressionTree::Node *n = new ExpressionTree::Node(operatorStack.top());
	operatorStack.pop();

	n->Right = operandStack.top();
	operandStack.pop();
	n->Left = operandStack.top();
	operandStack.pop();

	operandStack.push(n);
}
void ExpressionTree::FromString(const std::string &expressionString)
{
	// (1 +2)*3 => ( 1 + 2 ) * 3
	std::string str(expressionString);
	for (size_t i = 0; i < str.length(); ++i)
	{
		std::string op;
		op.push_back(str[i]);
		if (operators.find(op) != operators.end())
		{
			AddWhiteSpace(i + 1, i + 1, str);
			AddWhiteSpace(i - 1, i, str);
		}
	}

	// the algorithm:
	std::stack<std::string> operatorStack;
	operatorStack.push("#");
	std::stack<Node*> operandStack;

	// use the istream stream: treat a string as a bit of strings (can use << >> operators
	std::istringstream ss(str);
	while (!ss.eof())
	{
		std::string s;
		// skips whitespace for us:
		ss >> s;

		if (operators.find(s) != operators.end()){
			if (s == "(") {
				operatorStack.push(s);
			} else if(s == ")"){
				while (operatorStack.top() != "("){
					PopOperator(operatorStack, operandStack);
				}
				operatorStack.pop();
			}
			else if (operators[operatorStack.top()].Precedence >= operators[s].Precedence){
				PopOperator(operatorStack, operandStack);
				operatorStack.push(s);
			} else {
				operatorStack.push(s);
			}
		}
		else {
			Node *n = new Node(s);
			operandStack.push(n);
		}
	}

	while (operatorStack.top() != "#")
	{
		PopOperator(operatorStack, operandStack);
	}

	root = operandStack.top();
}

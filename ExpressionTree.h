#ifndef _EXPRESSION_TREE_
#define _EXPRESSION_TREE_

#include <string>
#include <stack>
#include <map>

class ExpressionTree
{
public:
	ExpressionTree(const std::string &str);
	~ExpressionTree();

	struct Node {
		Node(std::string v) : Value(v), Left(NULL), Right(NULL) {}
		std::string Value;
		Node *Left;
		Node *Right;
	};

	double Evaluate(Node *node = NULL) const; // the param is mostly for debugging purposes
	std::string Expression() const;

protected:
	// a static method means there is only a single representation of this function ("global", not per instance)
	// does not have access to the internal members(?)
	static  double Add(double x, double y) { return x + y; }
	static  double Subtract(double x, double y) { return x - y; }
	static  double Multiply(double x, double y) { return x * y; }
	static  double Divide(double x, double y) { return x / y; }

	// need a map to hold rules of operator and "maps" to the operator function (a function pointer!)
	// here is the function pointer:
	typedef double (*OperatorFunc) (double, double);

	// here is the operator functions to map to:
	struct OperatorInfo {
		OperatorInfo() {}
		OperatorInfo(int p, OperatorFunc f) : Precedence(p), Func(f) {}
		int Precedence;
		OperatorFunc Func;
	};

	// here is the map:
	typedef std::map<std::string, OperatorInfo> operator_map;
	static operator_map operators;

	// need a function to convert string input to our nodes:
	void FromString(const std::string &str);

private:
	Node *root;
	std::string expression;
};

#endif



// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Eval_Expr_Tree_Visitor.h"

//
//Eval_Expr_Tree_Visitor
//
Eval_Expr_Tree_Visitor::Eval_Expr_Tree_Visitor()
{

}

//
//~Eval_Expr_Tree_Visitor
//
Eval_Expr_Tree_Visitor::~Eval_Expr_Tree_Visitor()
{

}

//
//Visit_Num_Expr_Node
//
void Eval_Expr_Tree_Visitor::Visit_Num_Expr_Node(Num_Expr_Node & node)
{
	result_ = node.my_value();
}

//
//Visit_Unary_Expr_Node
//
void Eval_Expr_Tree_Visitor::Visit_Unary_Expr_Node(Unary_Expr_Node & node)
{
	Eval_Expr_Tree_Visitor un_node;
	node.getChild()->accept(un_node);
	result_ = -un_node.result();
}

//
//Visit_Add_Expr_Node
//
void Eval_Expr_Tree_Visitor::Visit_Add_Expr_Node(Add_Expr_Node & node)
{
	Eval_Expr_Tree_Visitor lhs_node;
	node.getLeftChild()->accept(lhs_node);
	int lhs_result = lhs_node.result();

	Eval_Expr_Tree_Visitor rhs_node;
	node.getRightChild()->accept(rhs_node);
	int rhs_result = rhs_node.result();

	result_ = lhs_result + rhs_result;
}

//
//Visit_Subtract_Expr_Node
//
void Eval_Expr_Tree_Visitor::Visit_Subtract_Expr_Node(Subtract_Expr_Node & node)
{
	Eval_Expr_Tree_Visitor lhs_node;
	node.getLeftChild()->accept(lhs_node);
	int lhs_result = lhs_node.result();

	Eval_Expr_Tree_Visitor rhs_node;
	node.getRightChild()->accept(rhs_node);
	int rhs_result = rhs_node.result();

	result_ = lhs_result - rhs_result;
}

//
//Visit_Multiply_Expr_Node
//
void Eval_Expr_Tree_Visitor::Visit_Multiply_Expr_Node(Multiply_Expr_Node & node)
{
	Eval_Expr_Tree_Visitor lhs_node;
	node.getLeftChild()->accept(lhs_node);
	int lhs_result = lhs_node.result();

	Eval_Expr_Tree_Visitor rhs_node;
	node.getRightChild()->accept(rhs_node);
	int rhs_result = rhs_node.result();

	result_ = lhs_result * rhs_result;
}

//
//Visit_Divide_Expr_Node
//
void Eval_Expr_Tree_Visitor::Visit_Divide_Expr_Node(Divide_Expr_Node & node)
{
	Eval_Expr_Tree_Visitor lhs_node;
	node.getLeftChild()->accept(lhs_node);
	int lhs_result = lhs_node.result();

	Eval_Expr_Tree_Visitor rhs_node;
	node.getRightChild()->accept(rhs_node);
	int rhs_result = rhs_node.result();

	if (rhs_result == 0)
		throw std::runtime_error("Divide by zero error!");
	result_ = lhs_result / rhs_result;
}

//
//Visit_Modulus_Expr_Node
//
void Eval_Expr_Tree_Visitor::Visit_Modulus_Expr_Node(Modulus_Expr_Node & node)
{
	Eval_Expr_Tree_Visitor lhs_node;
	node.getLeftChild()->accept(lhs_node);
	int lhs_result = lhs_node.result();

	Eval_Expr_Tree_Visitor rhs_node;
	node.getRightChild()->accept(rhs_node);
	int rhs_result = rhs_node.result();

	if (rhs_result == 0)
		throw std::runtime_error("Modulus by zero error!");
	result_ = lhs_result % rhs_result;
}

//
//result
//
int Eval_Expr_Tree_Visitor::result()
{
	return result_;
}
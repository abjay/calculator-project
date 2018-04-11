
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Unary_Expr_Node.h"
#include"Expr_Node_Visitor.h"

//
//Unary_Expr_Node
//
Unary_Expr_Node::Unary_Expr_Node(void)
	:child_(0)
{

}

//
//Unary_Expr_Node (Expr_Node *)
//
Unary_Expr_Node::Unary_Expr_Node(Expr_Node * child)
	:child_(child)
{

}

//
//~Unary_Expr_Node
//
Unary_Expr_Node::~Unary_Expr_Node(void)
{
	if (child_ != 0)
		delete child_;
}

//
//eval
//
int Unary_Expr_Node::eval(void)
{
	if (this->child_)
	{
		return -this->child_->eval();
	}
	return 0;
}

//
//accept
//
void Unary_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Unary_Expr_Node(*this);
}

//
//getChild
//
Expr_Node * Unary_Expr_Node::getChild(void)
{
	return this->child_;
}

//
//prec
//
int Unary_Expr_Node::prec(void)
{
	return 3;
}

//
//my_type
//
char Unary_Expr_Node::my_type(void)
{
	return 'u';
}
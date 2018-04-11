
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Subtract_Expr_Node.h"
#include"Expr_Node_Visitor.h"

//
//Subtract_Expr_Node
//
Subtract_Expr_Node::Subtract_Expr_Node()
{

}

//
//Subtract_Expr_Node (Expr_Node *, Expr_Node *)
//
Subtract_Expr_Node::Subtract_Expr_Node(Expr_Node * n1, Expr_Node * n2)
	:Binary_Expr_Node(n1, n2)
{

}

//
//~Subtract_Expr_Node
//
Subtract_Expr_Node::~Subtract_Expr_Node()
{

}

//
//execute_op
//
int Subtract_Expr_Node::execute_op(int num1, int num2)
{
	return num1 - num2;
}

//
//getLeftChild
//
Expr_Node * Subtract_Expr_Node::getLeftChild()
{
	return this->left_;
}

//
//getRightChild
//
Expr_Node * Subtract_Expr_Node::getRightChild()
{
	return this->right_;
}

//
//accept
//
void Subtract_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Subtract_Expr_Node(*this);
}

//
//prec
//
int Subtract_Expr_Node::prec(void)
{
	return 1;
}

//
//my_type
//
char Subtract_Expr_Node::my_type(void)
{
	return '-';
}
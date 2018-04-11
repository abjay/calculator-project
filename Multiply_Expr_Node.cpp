
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Multiply_Expr_Node.h"
#include"Expr_Node_Visitor.h"

//
//Multiply_Expr_Node
//
Multiply_Expr_Node::Multiply_Expr_Node()
{

}

//
//Multiply_Expr_Node (Expr_Node *, Expr_Node *)
//
Multiply_Expr_Node::Multiply_Expr_Node(Expr_Node * n1, Expr_Node * n2)
	:Binary_Expr_Node(n1, n2)
{

}

//
//~Multiply_Expr_Node
//
Multiply_Expr_Node::~Multiply_Expr_Node()
{

}

//
//execute_op
//
int Multiply_Expr_Node::execute_op(int num1, int num2)
{
	return num1 * num2;
}

//
//getLeftChild
//
Expr_Node * Multiply_Expr_Node::getLeftChild()
{
	return this->left_;
}

//
//getRightChild
//
Expr_Node * Multiply_Expr_Node::getRightChild()
{
	return this->right_;
}

//
//accept
//
void Multiply_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Multiply_Expr_Node(*this);
}

//
//prec
//
int Multiply_Expr_Node::prec(void)
{
	return 2;
}

//
//my_type
//
char Multiply_Expr_Node::my_type(void)
{
	return '*';
}
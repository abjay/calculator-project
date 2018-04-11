
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Modulus_Expr_Node.h"
#include"Expr_Node_Visitor.h"

//
//Modulus_Expr_Node
//
Modulus_Expr_Node::Modulus_Expr_Node()
{

}

//
//Modulus_Expr_Node (Expr_Node *, Expr_Node *)
//
Modulus_Expr_Node::Modulus_Expr_Node(Expr_Node * n1, Expr_Node * n2)
	:Binary_Expr_Node(n1, n2)
{

}

//
//~Modulus_Expr_Node
//
Modulus_Expr_Node::~Modulus_Expr_Node()
{

}

//
//execute_op
//
int Modulus_Expr_Node::execute_op(int num1, int num2)
{
	if (num2 == 0)
		throw std::runtime_error("Modulus by zero error!");
	return num1 % num2;
}

//
//getLeftChild
//
Expr_Node * Modulus_Expr_Node::getLeftChild()
{
	return this->left_;
}

//
//getRightChild
//
Expr_Node * Modulus_Expr_Node::getRightChild()
{
	return this->right_;
}

//
//accept
//
void Modulus_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Modulus_Expr_Node(*this);
}

//
//prec
//
int Modulus_Expr_Node::prec(void)
{
	return 2;
}

//
//my_type
//
char Modulus_Expr_Node::my_type(void)
{
	return '%';
}
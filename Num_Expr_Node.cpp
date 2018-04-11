
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Num_Expr_Node.h"
#include"Expr_Node_Visitor.h"

//
//Num_Expr_Node
//
Num_Expr_Node::Num_Expr_Node()
{

}

//
//Num_Expr_Node (int)
//
Num_Expr_Node::Num_Expr_Node(int num)
	:n_(num)
{

}

//
//~Num_Expr_Node
//
Num_Expr_Node::~Num_Expr_Node()
{

}

//
//eval
//
int Num_Expr_Node::eval()
{
	return n_;
}

//
//accept
//
void Num_Expr_Node::accept(Expr_Node_Visitor & v)
{
	v.Visit_Num_Expr_Node(*this);
}

//
//prec
//
int Num_Expr_Node::prec(void)
{
	return 4;
}

//
//my_type
//
char Num_Expr_Node::my_type(void)
{
	return 'n';
}

//
//my_value
//
int Num_Expr_Node::my_value(void)
{
	return n_;
}
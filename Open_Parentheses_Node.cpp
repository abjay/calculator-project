
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Open_Parentheses_Node.h"

//
//Open_Parentheses_Node
//
Open_Parentheses_Node::Open_Parentheses_Node()
{

}

//
//~Open_Parentheses_Node
//
Open_Parentheses_Node::~Open_Parentheses_Node()
{

}

//
//eval
//
int Open_Parentheses_Node::eval(void)
{
	return 1;
}

//
//accept
//
void Open_Parentheses_Node::accept(Expr_Node_Visitor & v)
{

}

//
//prec
//
int Open_Parentheses_Node::prec(void)
{
	return 0;
}

//
//my_type
//
char Open_Parentheses_Node::my_type(void)
{
	return '(';
}


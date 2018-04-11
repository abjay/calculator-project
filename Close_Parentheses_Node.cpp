
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Close_Parentheses_Node.h"

//
//Close_Parentheses_Node
//
Close_Parentheses_Node::Close_Parentheses_Node()
{

}

//
//~Close_Parentheses_Node
//
Close_Parentheses_Node::~Close_Parentheses_Node()
{

}

//
//eval
//
int Close_Parentheses_Node::eval(void)
{
	return 1;
}

//
//accept
//
void Close_Parentheses_Node::accept(Expr_Node_Visitor & v)
{

}

//
//prec
//
int Close_Parentheses_Node::prec(void)
{
	return 0;
}

//
//my_type
//
char Close_Parentheses_Node::my_type(void)
{
	return ')';
}


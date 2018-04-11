
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include<sstream>
#include<string>
#include"Binary_Expr_Node.h"


//
//Binary_Expr_Node
//
Binary_Expr_Node::Binary_Expr_Node()
	:left_(0),
	right_(0)
{

}

//
//Binary_Expr_Node (Expr_Node *, Expr_Node *)
//
Binary_Expr_Node::Binary_Expr_Node(Expr_Node * n1, Expr_Node * n2)
	:left_(n1),
	right_(n2)
{

}

//
//~Binary_Expr_Node
//
Binary_Expr_Node::~Binary_Expr_Node()
{
	if (left_ != 0)
		delete left_;
	if (right_ != 0)
		delete right_;
}

//
//eval
//
int Binary_Expr_Node::eval()
{
	int num1 = left_->eval();
	int num2 = right_->eval();
	int result = this->execute_op(num1, num2);
	return result;
}
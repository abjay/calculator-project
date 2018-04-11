// -*- C++ -*-

//==============================================================================
/**
* @file       Divide_Expr_Node.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef DIVIDE_EXPR_NODE_H_
#define DIVIDE_EXPR_NODE_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Binary_Expr_Node.h"

/**
* @class Divide_Expr_Node
*
* Implementation of a division node
*/
class Divide_Expr_Node : public Binary_Expr_Node
{
public:
	/// Default constructor
	Divide_Expr_Node(void);

	/**
	* Initializing constructor
	*
	* @param[in]		n1		child node
	* @param[in]		n2		child node
	*/
	Divide_Expr_Node(Expr_Node * n1, Expr_Node * n2);

	/// Destructor
	virtual ~Divide_Expr_Node(void);

	/**
	* Execute the current operation
	*
	* @param[in]		num1		number in child node
	* @param[in]		num2		number in child node
	* @return						the result
	*/
	virtual int execute_op(int num1, int num2);

	/**
	* Get the left child node
	*
	* @return						the left child node
	*/
	virtual Expr_Node * getLeftChild();

	/**
	* Get the right child node
	*
	* @return						the right child node
	*/
	virtual Expr_Node * getRightChild();

	/**
	* Accept the visitor
	*
	* @param[in]		v		the visitor type
	*/
	virtual void accept(Expr_Node_Visitor & v);

	/**
	* Get the precedence of the operator
	*
	* @return						the precendence
	*/
	virtual int prec(void);

	/**
	* Get the operator
	*
	* @return						the operator
	*/
	virtual char my_type(void);
};
#endif		// !defined DIVIDE_EXPR_NODE_H_
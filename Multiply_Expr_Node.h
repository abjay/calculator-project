// -*- C++ -*-

//==============================================================================
/**
* @file       Multiply_Expr_Node.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef MULTIPLY_EXPR_NODE_H_
#define MULTIPLY_EXPR_NODE_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Expr_Node.h"
#include"Binary_Expr_Node.h"

/**
* @class Multiply_Expr_Node
*
* Implementation of a multiplication node
*/
class Multiply_Expr_Node : public Binary_Expr_Node
{
public:
	/// Default constructor
	Multiply_Expr_Node(void);

	/**
	* Initializing constructor
	*
	* @param[in]		n1		child node
	* @param[in]		n2		child node
	*/
	Multiply_Expr_Node(Expr_Node * n1, Expr_Node * n2);

	/// Destructor
	virtual ~Multiply_Expr_Node(void);

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

#endif		// !defined MULTIPLY_EXPR_NODE_H_
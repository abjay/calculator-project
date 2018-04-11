// -*- C++ -*-

//==============================================================================
/**
* @file       Binary_Expr_Node.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef BINARY_EXPR_NODE_H_
#define BINARY_EXPR_NODE_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Expr_Node.h"

/**
* @class Binary_Expr_Node
*
* Implementation of a binary expression node
*/
class Binary_Expr_Node : public Expr_Node
{
public:
	/// Default constructor.
	Binary_Expr_Node(void);

	/**
	* Initializing constructor.
	*
	* @param[in]      n1        child node
	* @param[in]      n2        child node
	*/
	Binary_Expr_Node(Expr_Node * n1, Expr_Node * n2);

	/// Destructor
	virtual ~Binary_Expr_Node(void);

	/**
	* Execute the current operation
	*
	* @param[in]		num1		number in child node
	* @param[in]		num2		number in child node
	* @return						the result
	*/
	virtual int execute_op(int n1, int n2) = 0;

	/**
	* Evaluate the current node
	*
	* @return						the result
	*/
	virtual int eval(void);

	/**
	* Get the left child node
	*
	* @return						the left child node
	*/
	virtual Expr_Node * getLeftChild() = 0;

	/**
	* Get the right child node
	*
	* @return						the right child node
	*/
	virtual Expr_Node * getRightChild() = 0;

	/**
	* Accept the visitor
	*
	* @param[in]		v		the visitor type
	*/
	virtual void accept(Expr_Node_Visitor & v) = 0;

	/**
	* Get the precedence of the operator
	*
	* @return						the precendence
	*/
	virtual int prec(void) = 0;

	/**
	* Get the operator
	*
	* @return						the operator
	*/
	virtual char my_type(void) = 0;

protected:
	//Child nodes
	Expr_Node * left_;
	Expr_Node * right_;
};


#endif		// !defined BINARY_EXPR_NODE_H_
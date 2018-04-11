// -*- C++ -*-

//==============================================================================
/**
* @file       Unary_Expr_Node.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef UNARY_EXPR_NODE_H_
#define UNARY_EXPR_NODE_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Expr_Node.h"

/**
* @class Unary_Expr_Node
*
* Implementation of a unary expression node
*/
class Unary_Expr_Node : public Expr_Node
{
public:
	/// Default constructor
	Unary_Expr_Node(void);

	/**
	* Initializing constructor.
	*
	* @param[in]      child        node to be initialized
	*/
	Unary_Expr_Node(Expr_Node * child);

	/// Destructor
	virtual ~Unary_Expr_Node(void);

	/**
	* Evaluate the node
	*
	* @return						the result
	*/
	virtual int eval(void);

	/**
	* Accept the visitor
	*
	* @param[in]		v		the visitor type
	*/
	virtual void accept(Expr_Node_Visitor & v);

	/**
	* Get the child node
	*
	* @return						the child node
	*/
	virtual Expr_Node * getChild(void);

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

private:
	//Variable to store the child node
	Expr_Node * child_;
};

#endif		// !defined UNARY_EXPR_NODE_H_
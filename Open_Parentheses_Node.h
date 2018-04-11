// -*- C++ -*-

//==============================================================================
/**
* @file       Open_Parentheses_Node.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef OPEN_PARENTHESES_NODE_H_
#define OPEN_PARENTHESES_NODE_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Expr_Node.h"

/**
* @class Num_Expr_Node
*
* Implementation of an open parentheses node
*/
class Open_Parentheses_Node : public Expr_Node
{
public:
	/// Default constructor
	Open_Parentheses_Node(void);

	/// Destructor
	virtual ~Open_Parentheses_Node(void);

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

#endif		// !defined OPEN_PARENTHESES_NODE_H_
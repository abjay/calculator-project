// -*- C++ -*-

//==============================================================================
/**
* @file       Expr_Node.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef EXPR_NODE_H_
#define EXPR_NODE_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>

//Forward declaration
class Expr_Node_Visitor;

/**
* @class Expr_Node
*
* Implementation of the base expression node
*/
class Expr_Node
{
public:
	/// Default constructor
	Expr_Node(void);

	/// Destructor
	virtual ~Expr_Node(void);

	/**
	* Evaluate the node
	*
	* @return						the result
	*/
	virtual int eval(void) = 0;
	
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
};

#endif		// !defined EXPR_NODE_H_
// -*- C++ -*-

//==============================================================================
/**
* @file       Num_Expr_Node.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef NUM_EXPR_NODE_H_
#define NUM_EXPR_NODE_H_

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
* Implementation of a number node
*/
class Num_Expr_Node : public Expr_Node
{
public:
	/// Default constructor
	Num_Expr_Node(void);

	/**
	* Initializing constructor.
	*
	* @param[in]      num        value to be initialized
	*/
	Num_Expr_Node(int num);

	/// Destructor
	virtual ~Num_Expr_Node(void);

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

	/**
	* Get the value
	*
	* @return						the number
	*/
	virtual int my_value(void);

private:
	//Variable to store number
	int n_;
};

#endif		// !defined NUM_EXPR_NODE_H_
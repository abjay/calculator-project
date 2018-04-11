// -*- C++ -*-

//==============================================================================
/**
* @file       Expr_Node_Visitor.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef EXPR_NODE_VISITOR_H_
#define EXPR_NODE_VISITOR_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Expr_Node.h"
#include"Num_Expr_Node.h"
#include"Unary_Expr_Node.h"
#include"Add_Expr_Node.h"
#include"Subtract_Expr_Node.h"
#include"Multiply_Expr_Node.h"
#include"Divide_Expr_Node.h"
#include"Modulus_Expr_Node.h"
#include"Open_Parentheses_Node.h"
#include"Close_Parentheses_Node.h"

/**
* @class Expr_Node_Visitor
*
* Implementation of a node visitor base class
*/
class Expr_Node_Visitor
{
public:
	/// Default constructor
	Expr_Node_Visitor(void);

	/// Destructor
	virtual ~Expr_Node_Visitor(void);

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Num_Expr_Node(Num_Expr_Node & node) = 0;

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Unary_Expr_Node(Unary_Expr_Node & node) = 0;

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Add_Expr_Node(Add_Expr_Node & node) = 0;

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Subtract_Expr_Node(Subtract_Expr_Node & node) = 0;

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Multiply_Expr_Node(Multiply_Expr_Node & node) = 0;

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Divide_Expr_Node(Divide_Expr_Node & node) = 0;

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Modulus_Expr_Node(Modulus_Expr_Node & node) = 0;
};

#endif		// !defined EXPR_NODE_VISITOR_H_
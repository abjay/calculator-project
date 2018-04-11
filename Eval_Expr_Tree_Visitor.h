// -*- C++ -*-

//==============================================================================
/**
* @file       Eval_Expr_Tree_Visitor.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef EVAL_EXPR_TREE_VISITOR_H_
#define EVAL_EXPR_TREE_VISITOR_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Expr_Node.h"
#include"Expr_Node_Visitor.h"

/**
* @class Eval_Expr_Tree_Visitor
*
* Implementation of a tree visitor concrete class
*/
class Eval_Expr_Tree_Visitor : public Expr_Node_Visitor
{
public:
	/// Default constructor
	Eval_Expr_Tree_Visitor(void);

	/// Destructor
	virtual ~Eval_Expr_Tree_Visitor(void);

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Num_Expr_Node(Num_Expr_Node & node);

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Unary_Expr_Node(Unary_Expr_Node & node);

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Add_Expr_Node(Add_Expr_Node & node);

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Subtract_Expr_Node(Subtract_Expr_Node & node);

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Multiply_Expr_Node(Multiply_Expr_Node & node);

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Divide_Expr_Node(Divide_Expr_Node & node);

	/**
	* Visit the node to perform operation
	*
	* @param[in]		node		node to be visited
	*/
	virtual void Visit_Modulus_Expr_Node(Modulus_Expr_Node & node);

	/**
	* Return the result
	*
	* @return						the result
	*/
	int result(void);

private:
	//Variable to store the result
	int result_;
};

#endif		// !defined EVAL_EXPR_TREE_VISITOR_H_
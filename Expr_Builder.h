// -*- C++ -*-

//==============================================================================
/**
* @file       Expr_Builder.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef EXPR_BUILDER_H_
#define EXPR_BUILDER_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Expr_Node.h"
#include"Stack.h"

/**
* @class Expr_Builder
*
* Implementation of a builder
*/
class Expr_Builder
{
public:
	/// Default constructor
	Expr_Builder(void);

	/// Destructor
	virtual ~Expr_Builder(void);

	/**
	* Build the initial expression
	*/
	virtual void build_expression(void) = 0;

	/**
	* Build the number node
	*/
	virtual void build_number(int n) = 0;

	/**
	* Build the unary node
	*/
	virtual void build_unary_operand(void) = 0;

	/**
	* Build the add node
	*/
	virtual void build_add_operand(void) = 0;

	/**
	* Build the subtract node
	*/
	virtual void build_subtract_operand(void) = 0;

	/**
	* Build the multiply node
	*/
	virtual void build_multiply_operand(void) = 0;

	/**
	* Build the division node
	*/
	virtual void build_division_operand(void) = 0;

	/**
	* Build the modulus node
	*/
	virtual void build_modulus_operand(void) = 0;

	/**
	* Build the open parentheses node
	*/
	virtual void build_open_parentheses(void) = 0;

	/**
	* Build the close parentheses node
	*/
	virtual void build_close_parentheses(void) = 0;

	/**
	* Build the empty unary node
	*/
	virtual void build_empty_unary_operand(void) = 0;

	/**
	* Build the empty add node
	*/
	virtual void build_empty_add_operand(void) = 0;

	/**
	* Build the empty subtract node
	*/
	virtual void build_empty_subtract_operand(void) = 0;

	/**
	* Build the empty multiply node
	*/
	virtual void build_empty_multiply_operand(void) = 0;

	/**
	* Build the empty divide node
	*/
	virtual void build_empty_divide_operand(void) = 0;

	/**
	* Build the empty modulus node
	*/
	virtual void build_empty_modulus_operand(void) = 0;

	/**
	* Build the empty parentheses node
	*/
	virtual void build_empty_parentheses(void) = 0;

	/**
	* Build the operator tree
	*
	* @param[in]		token		token to be built into a tree
	*/
	virtual void build_op(char token) = 0;

	/**
	* Return the expression tree
	*
	* @return						the expression tree
	*/
	virtual Expr_Node * get_expression(void) = 0;

protected:
	//Stacks to store expression nodes and operator nodes
	Stack<Expr_Node*> expr_stack;
	Stack<Expr_Node*> op_stack;
};

#endif		// !defined EXPR_BUILDER_H_
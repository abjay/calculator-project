// -*- C++ -*-

//==============================================================================
/**
* @file       Calculator.h
*
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include<cstdio>
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"Expr_Builder.h"
#include"Expr_Tree_Builder.h"
#include"Stack.h"
#include"Eval_Expr_Tree_Visitor.h"

/**
* @class Calculator
*
* Implementation of a simple calculator
*/
class Calculator
{
public:
	/// Default constructor
	Calculator(void);

	/// Destructor
	virtual ~Calculator(void);

	/**
	* Check if token is an operator
	*
	* @param[in]		token			token to be tested
	* @return							boolean value to indicate token
	*/
	bool is_operator(std::string token);

	/**
	* Parse the expression
	*
	* @param[in]		infix			infix string
	* @param[in]		b				the desired builder
	* @return							boolean value to indicate success
	*/
	bool parse_expr(const std::string & infix, Expr_Builder & b);

	/**
	* Evaluate the expression
	*
	* @param[in]		infix			infix string
	* @return							the result
	*/
	int evaluate_expr(const std::string & infix);

	/**
	* Check for expression validity
	*
	* @param[in]		infix			infix string
	* @return							boolean value to indicate success
	*/
	bool valid_expression(const std::string & infix);
};

#endif		// !defined CALCULATOR_H_
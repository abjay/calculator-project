#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include<sstream>
#include<string>
#include"Expr_Node.h"
#include"Binary_Expr_Node.h"
#include"Calculator.h"
#include"Expr_Builder.h"
#include"Expr_Tree_Builder.h"
#include"Expr_Node_Visitor.h"
#include"Eval_Expr_Tree_Visitor.h"
#include"Num_Expr_Node.h"
#include"Unary_Expr_Node.h"
#include"Add_Expr_Node.h"
#include"Subtract_Expr_Node.h"
#include"Multiply_Expr_Node.h"
#include"Divide_Expr_Node.h"
#include"Modulus_Expr_Node.h"
#include"Open_Parentheses_Node.h"
#include"Close_Parentheses_Node.h"

int main (int argc, char * argv [])
{
	Calculator c;
	std::string infix;

	while (1)
	{
		std::cout << "Enter an expression:" << std::endl;
		std::getline(std::cin, infix);
		if (infix == "QUIT") break;

		try
		{
			//Evaluate expression and get result
			int res = c.evaluate_expr(infix);
			std::cout << res << std::endl;
		}
		//Catching invalid expression, division by zero, modulus by zero errors
		catch (std::exception & exp)
		{
			std::cout << exp.what() << std::endl;
		}
	}
	return 0;
}
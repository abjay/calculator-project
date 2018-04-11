
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Calculator.h"

//
//Calculator
//
Calculator::Calculator()
{

}

//
//~Calculator
//
Calculator::~Calculator()
{

} 

//
//is_operator
//
bool Calculator::is_operator(std::string token)
{
	if (token == "+") return true;
	else if (token == "-") return true;
	else if (token == "*") return true;
	else if (token == "/") return true;
	else if (token == "%") return true;
	else return false;
}



//
//valid_expression
//
bool Calculator::valid_expression(const std::string & infix)
{
	//Checking if user has entered input
	if (infix.size() == 0)
		return false;
	//Checking if the infix expression contains white spaces at the beginning and end
	int end = infix.size() - 1;
	if (infix[end] == ' ')
	{
		return false;
	}
	if (infix[0] == ' ')
	{
		return false;
	}
	//Checking for infix expression
	if ((infix[0] == '+') || (infix[0] == '/') || (infix[0] == '%'))
	{
		return false;
	}
	//Checking for unary minus
	int l_u_minus = 0;
	if (infix[0] == '-')
	{
		int position1 = infix.find_first_of("0123456789");
		if ((position1 == 1) || (position1 == 2) || (position1 == 3))
			l_u_minus = 1;

		std::istringstream input4(infix);
		std::string token4;
		int validity_count4 = 1;
		int inc_count = 0;
		while (input4 >> token4)
		{
			inc_count++;
			if ((inc_count == 1) && (token4 == "-") && (l_u_minus == 1))
			{
				validity_count4 = 1;
			}
			else if (isdigit(token4[0]))
				validity_count4--;
			else if ((token4.size() >= 2) && (atoi(token4.c_str())))
				validity_count4--;
			else if ((token4 == "+") || (token4 == "-") || (token4 == "*") || (token4 == "/") || (token4 == "%"))
				validity_count4++;
		}
		if (validity_count4 < 0)
		{
			return false;
		}
	}

	int pos = infix.find(' ');
	if (pos == 0)
	{
		return false;
	}
	for (size_t i = 0; i < infix.size(); i++)
	{
		//Finding consecutive white spaces
		int spos = infix.find(' ', pos + 1);
		if (spos == pos + 1)
		{
			return false;
		}
		pos = spos;
	}

	//Making sure that an expression is entered rather than just a number
	if ((infix.find_first_of("+-*/%")) == std::string::npos)
	{
		return false;
	}

	//Used to check validity of expression
	int validity_count1 = 1;
	int binary_op_count = 0;
	int unary_bit = 0;
	for (size_t i = 0; i < infix.size(); i++)
	{
		//Checking if character is an operator
		if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '%'))
		{
			//If it is an operator increment by 1
			validity_count1++;
			binary_op_count++;
		}
		//Double checking for unary minus operator
		if (infix[i] == '-')
		{
			int mpos = infix.find_first_of("0123456789", i + 1);
			//Checking if the minus is negation
			if (mpos == i + 1)
			{
				//Decrement by 1 since its a unary operator
				validity_count1--;
				binary_op_count--;
			}
			//Checking if the minus is unary
			if (((mpos == i + 2) && (i == 0)) || ((mpos == i + 2) && ((infix[i - 2] == '(') || (infix[i - 2] == '+') || (infix[i - 2] == '-') || (infix[i - 2] == '*') || (infix[i - 2] == '/') || (infix[i - 2] == '%'))))
			{
				validity_count1--;
				binary_op_count--;
				unary_bit = 1;
			}
			//Checking if the minus is unary of negation
			if (((mpos == i + 3) && (i == 0)) || ((mpos == i + 3) && ((infix[i - 2] == '(') || (infix[i - 2] == '+') || (infix[i - 2] == '-') || (infix[i - 2] == '*') || (infix[i - 2] == '/') || (infix[i - 2] == '%'))))
			{
				validity_count1--;
				binary_op_count--;
				unary_bit = 1;
			}
			//Checking for unary parenthesized expression
			if (((infix[i + 2] == '(') && (i == 0)) || ((infix[i + 2] == '(') && ((infix[i - 2] == '(') || (infix[i - 2] == '+') || (infix[i - 2] == '-') || (infix[i - 2] == '*') || (infix[i - 2] == '/') || (infix[i - 2] == '%'))))
			{
				validity_count1--;
				binary_op_count--;
				unary_bit = 1;
			}
		}
	}
	//If there are no binary operators then throw exception
	if (binary_op_count <= 0)
	{
		return false;
	}
	//Checking if operands and operators are balanced
	std::istringstream input2(infix);
	std::string token2;
	while (input2 >> token2)
	{
		if (isdigit(token2[0]))
			validity_count1--;
		else if ((token2.size() >= 2) && (atoi(token2.c_str())))
			validity_count1--;
	}
	//If the expression is unbalanced
	if (validity_count1 != 0)
	{
		return false;
	}

	//Checking if the expression does not contain any numbers
	if (infix.find_first_of("0123456789") == std::string::npos)
	{
		return false;
	}

	//Checking if postfix expression is entered
	std::istringstream input3(infix);
	std::string token3;
	int validity_count2 = 1;
	while (input3 >> token3)
	{
		if ((isdigit(token3[0])) || (atoi(token3.c_str())))
		{
			validity_count2--;
			if (validity_count2 < 0)
			{
				return false;
			}
		}
		else if ((token3[0] == '+') || (token3[0] == '-') || (token3[0] == '*') || (token3[0] == '/') || (token3[0] == '%'))
			validity_count2++;
	}
	//Checking for letters
	if ((infix.find_first_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos) || (infix.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos))
	{
		return false;
	}
	//Checking for balanced parentheses
	int p_count = 0;
	int db_pos = 0;
	int bb_pos = 0;
	for (size_t i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
			p_count++;
			//Checking for arbitrary parentheses
			if (infix[i + 1] != ' ')
				return false;
			if (i != 0)
			{
				if (infix[i - 1] != ' ')
					return false;
			}
			//Checking for absence of digits between parentheses
			db_pos = infix.find_first_of("0123456789", i + 1);
			bb_pos = infix.find_first_of(')', i + 1);
			if ((db_pos >= bb_pos) || (db_pos == std::string::npos))
				return false;
		}
		if (infix[i] == ')')
		{
			p_count--;
			//Checking for arbitrary parentheses
			if (infix[i - 1] != ' ')
				return false;
			if (i != (infix.size() - 1))
			{
				if (infix[i + 1] != ' ')
					return false;
			}
		}
		if (p_count < 0)
			return false;
	}
	if (p_count != 0)
		return false;

	
	return true;
}

//
//parse_expr
//
bool Calculator::parse_expr(const std::string & infix, Expr_Builder & b)
{
	std::istringstream input(infix);
	std::string token;
	Stack<char> op_stack;
	//Operator and digit bits to keep track of unary operator
	int o_bit = 0;
	int d_bit = 0;

	b.build_expression();

	while (input >> token)
	{
		if (token == "(")
		{
			b.build_open_parentheses();
		}
		else if ((isdigit(token[0])) || ((token.size() >= 2) && (atoi(token.c_str()))))
		{
			d_bit++;
			int val = atoi(token.c_str());
			b.build_number(val);
		}
		else if (is_operator(token))
		{
			o_bit++;
			//Condition to check for unary operator
			if (o_bit > d_bit) 
			{
				b.build_unary_operand();
				o_bit--;
				continue;
			}

			//Building the respective operator tree
			if (token == "+") b.build_add_operand();
			else if (token == "-") b.build_subtract_operand();
			else if (token == "*") b.build_multiply_operand();
			else if (token == "/") b.build_division_operand();
			else if (token == "%") b.build_modulus_operand();
		}
		else if (token == ")")
		{
			//Building expression in parentheses
			b.build_close_parentheses();
		}
		else
		{
			//If something other than a number is entered
			return false;
		}
	}
	return true;
}

//
//evaluate_expr
//
int Calculator::evaluate_expr(const std::string & infix)
{
	if (!(valid_expression(infix)))
	{
		throw std::runtime_error("Invalid expression!");
	}
	Expr_Tree_Builder b;
	if (!(this->parse_expr(infix, b)))
		return false;
	//Getting the expression tree
	Expr_Node * expr = b.get_expression();

	//Visitor for postfix traversal
	Eval_Expr_Tree_Visitor eval;

	if (0 == expr)
		return false;
	try
	{
		expr->accept(eval);
	}
	catch (std::exception)
	{
		if (expr !=  0)
			delete expr;
		throw;
	}
	
	int result = eval.result();
	delete expr;

	return result;

}
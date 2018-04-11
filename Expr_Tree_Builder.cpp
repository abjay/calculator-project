
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Expr_Tree_Builder.h"

//
//Expr_Tree_Builder
//
Expr_Tree_Builder::Expr_Tree_Builder()
{

}

//
//~Expr_Tree_Builder
//
Expr_Tree_Builder::~Expr_Tree_Builder()
{
	
}

//
//build_number
//
void Expr_Tree_Builder::build_number(int n)
{
	Expr_Node * tree_ = factory.create_num_node(n);
	expr_stack.push(tree_);
}

//
//build_unary_operand
//
void Expr_Tree_Builder::build_unary_operand(void)
{
	build_empty_unary_operand();
	if (!(op_stack.is_empty()))
	{
		//If there is already a unary present on stack top, build it
		while (op_stack.top()->my_type() == 'u')
		{
			build_op(op_stack.top()->my_type());
			delete op_stack.top();
			op_stack.pop();
		}
	}
	op_stack.push(empty_node);
}

//
//build_add_operand
//
void Expr_Tree_Builder::build_add_operand(void)
{
	build_empty_add_operand();

	if (op_stack.is_empty())
	{
		op_stack.push(empty_node);
	}
	else if (op_stack.top()->my_type() == '(')
	{
		op_stack.push(empty_node);
	}
	//If stack top's precedence is higher then building operator tree
	else if (op_stack.top()->prec() >= empty_node->prec())
	{
		while (op_stack.top()->prec() >= empty_node->prec())
		{
			build_op(op_stack.top()->my_type());
			delete op_stack.top();
			op_stack.pop();
			if ((op_stack.is_empty()) || (op_stack.top()->my_type() == '('))
			{
				op_stack.push(empty_node);
				break;
			}
		}
		if (op_stack.top()->prec() < empty_node->prec())
		{
			op_stack.push(empty_node);
		}
	}
	//If stack top's precedence is lower then pushing token node onto stack
	else if (op_stack.top()->prec() < empty_node->prec())
	{
		op_stack.push(empty_node);
	}
}

//
//build_subtract_operand
//
void Expr_Tree_Builder::build_subtract_operand(void)
{

	build_empty_subtract_operand();

	if (op_stack.is_empty())
	{
		op_stack.push(empty_node);
	}
	else if (op_stack.top()->my_type() == '(')
	{
		op_stack.push(empty_node);
	}
	//If stack top's precedence is higher then building operator tree
	else if (op_stack.top()->prec() >= empty_node->prec())
	{
		while (op_stack.top()->prec() >= empty_node->prec())
		{
			build_op(op_stack.top()->my_type());
			delete op_stack.top();
			op_stack.pop();
			if ((op_stack.is_empty()) || (op_stack.top()->my_type() == '('))
			{
				op_stack.push(empty_node);
				break;
			}
		}
		if (op_stack.top()->prec() < empty_node->prec())
		{
			op_stack.push(empty_node);
		}
	}
	//If stack top's precedence is lower then pushing token node onto stack
	else if (op_stack.top()->prec() < empty_node->prec())
	{
		op_stack.push(empty_node);
	}
}

//
//build_multiply_operand
//
void Expr_Tree_Builder::build_multiply_operand(void)
{
	build_empty_multiply_operand();

	if (op_stack.is_empty())
	{
		op_stack.push(empty_node);
	}
	else if (op_stack.top()->my_type() == '(')
	{
		op_stack.push(empty_node);
	}
	//If stack top's precedence is higher then building operator tree
	else if (op_stack.top()->prec() >= empty_node->prec())
	{
		while (op_stack.top()->prec() >= empty_node->prec())
		{
			build_op(op_stack.top()->my_type());
			delete op_stack.top();
			op_stack.pop();
			if ((op_stack.is_empty()) || (op_stack.top()->my_type() == '('))
			{
				op_stack.push(empty_node);
				break;
			}
		}
		if (op_stack.top()->prec() < empty_node->prec())
		{
			op_stack.push(empty_node);
		}
	}
	//If stack top's precedence is lower then pushing token node onto stack
	else if (op_stack.top()->prec() < empty_node->prec())
	{
		op_stack.push(empty_node);
	}
}

//
//build_division_operand
//
void Expr_Tree_Builder::build_division_operand(void)
{
	build_empty_divide_operand();

	if (op_stack.is_empty())
	{
		op_stack.push(empty_node);
	}
	else if (op_stack.top()->my_type() == '(')
	{
		op_stack.push(empty_node);
	}
	//If stack top's precedence is higher then building operator tree
	else if (op_stack.top()->prec() >= empty_node->prec())
	{
		while (op_stack.top()->prec() >= empty_node->prec())
		{
			build_op(op_stack.top()->my_type());
			delete op_stack.top();
			op_stack.pop();
			if ((op_stack.is_empty()) || (op_stack.top()->my_type() == '('))
			{
				op_stack.push(empty_node);
				break;
			}
		}
		if (op_stack.top()->prec() < empty_node->prec())
		{
			op_stack.push(empty_node);
		}
	}
	//If stack top's precedence is lower then pushing token node onto stack
	else if (op_stack.top()->prec() < empty_node->prec())
	{
		op_stack.push(empty_node);
	}
}

//
//build_modulus_operand
//
void Expr_Tree_Builder::build_modulus_operand(void)
{
	build_empty_modulus_operand();

	if (op_stack.is_empty())
	{
		op_stack.push(empty_node);
	}
	else if (op_stack.top()->my_type() == '(')
	{
		op_stack.push(empty_node);
	}
	//If stack top's precedence is higher then building operator tree
	else if (op_stack.top()->prec() >= empty_node->prec())
	{
		while (op_stack.top()->prec() >= empty_node->prec())
		{
			build_op(op_stack.top()->my_type());
			delete op_stack.top();
			op_stack.pop();
			if ((op_stack.is_empty()) || (op_stack.top()->my_type() == '('))
			{
				op_stack.push(empty_node);
				break;
			}
		}
		if (op_stack.top()->prec() < empty_node->prec())
		{
			op_stack.push(empty_node);
		}
	}
	//If stack top's precedence is lower then pushing token node onto stack
	else if (op_stack.top()->prec() < empty_node->prec())
	{
		op_stack.push(empty_node);
	}
}

//
//build_open_parentheses
//
void Expr_Tree_Builder::build_open_parentheses(void)
{
	build_empty_parentheses();
	op_stack.push(empty_node);
}

//
//build_close_parentheses
//
void Expr_Tree_Builder::build_close_parentheses(void)
{
	//Building expression in parentheses
	while (!(op_stack.top()->my_type() == '('))
	{
		build_op(op_stack.top()->my_type());
		delete op_stack.top();
		op_stack.pop();
		if (op_stack.is_empty()) break;
	}
	if (!(op_stack.is_empty()))
	{
		//Popping out '(' open parentheses
		delete op_stack.top();
		op_stack.pop();
	}
}

//
//build_empty_unary_operand
//
void Expr_Tree_Builder::build_empty_unary_operand(void)
{
	empty_node = factory.create_empty_unary_node();
}

//
//build_empty_add_operand
//
void Expr_Tree_Builder::build_empty_add_operand(void)
{
	empty_node = factory.create_empty_add_node();
}

//
//build_empty_subtract_operand
//
void Expr_Tree_Builder::build_empty_subtract_operand(void)
{
	empty_node = factory.create_empty_subtract_node();
}

//
//build_empty_multiply_operand
//
void Expr_Tree_Builder::build_empty_multiply_operand(void)
{
	empty_node = factory.create_empty_multiply_node();
}

//
//build_empty_divide_operand
//
void Expr_Tree_Builder::build_empty_divide_operand(void)
{
	empty_node = factory.create_empty_divide_node();
}

//
//build_empty_modulus_operand
//
void Expr_Tree_Builder::build_empty_modulus_operand(void)
{
	empty_node = factory.create_empty_modulus_node();
}

//
//build_empty_parentheses
//
void Expr_Tree_Builder::build_empty_parentheses(void)
{
	empty_node = factory.create_parentheses_node();
}

//
//build_op
//
void Expr_Tree_Builder::build_op(char token)
{
	if (token == '+')
	{
		//Creating add node with the first two elements on stack
		Expr_Node * n2 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * n1 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * tree_ = factory.create_add_node(n1, n2);
		expr_stack.push(tree_);
	}
	else if (token == '-')
	{
		//Creating subtract node with the first two elements on stack
		Expr_Node * n2 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * n1 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * tree_ = factory.create_sub_node(n1, n2);
		expr_stack.push(tree_);
	}
	else if (token == '*')
	{
		//Creating multiply node with the first two elements on stack
		Expr_Node * n2 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * n1 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * tree_ = factory.create_mul_node(n1, n2);
		expr_stack.push(tree_);
	}
	else if (token == '/')
	{
		//Creating division node with the first two elements on stack
		Expr_Node * n2 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * n1 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * tree_ = factory.create_div_node(n1, n2);
		expr_stack.push(tree_);
	}
	else if (token == '%')
	{
		//Creating modulus node with the first two elements on stack
		Expr_Node * n2 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * n1 = expr_stack.top();
		expr_stack.pop();
		Expr_Node * tree_ = factory.create_mod_node(n1, n2);
		expr_stack.push(tree_);
	}
	else if (token == 'u')
	{
		//Creating unary node with the first two elements on stack
		Expr_Node * n1 = expr_stack.top();
		Expr_Node * tree_ = factory.create_unary_node(n1);
		expr_stack.pop();
		expr_stack.push(tree_);
	}
}

Expr_Node * Expr_Tree_Builder::get_expression(void)
{
	//Storing the remaining operators from stack
	while (!(op_stack.is_empty()))
	{
		build_op(op_stack.top()->my_type());
		delete op_stack.top();
		op_stack.pop();
	}
	//Deleting leftover elements
	if (!(op_stack.is_empty()))
	{
		for (size_t i = 0; i < op_stack.size(); i++)
		{
			delete op_stack.top();
			op_stack.pop();
		}
	}

	this->tree_ = expr_stack.top();
	return this->tree_;
}
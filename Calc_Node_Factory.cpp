
// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include"Calc_Node_Factory.h"

//
//Calc_Node_Factory
//
Calc_Node_Factory::Calc_Node_Factory()
{

}

//
//~Calc_Node_Factory
//
Calc_Node_Factory::~Calc_Node_Factory(void)
{

}

//
//create_num_node
//
Num_Expr_Node * Calc_Node_Factory::create_num_node(int n)
{
	return new Num_Expr_Node(n);
}

//
//create_unary_node
//
Unary_Expr_Node * Calc_Node_Factory::create_unary_node(Expr_Node * n1)
{
	return new Unary_Expr_Node(n1);
}

//
//create_add_node
//
Add_Expr_Node * Calc_Node_Factory::create_add_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Add_Expr_Node(n1, n2);
}

//
//create_sub_node
//
Subtract_Expr_Node * Calc_Node_Factory::create_sub_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Subtract_Expr_Node(n1, n2);
}

//
//create_mul_node
//
Multiply_Expr_Node * Calc_Node_Factory::create_mul_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Multiply_Expr_Node(n1, n2);
}

//
//create_div_node
//
Divide_Expr_Node * Calc_Node_Factory::create_div_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Divide_Expr_Node(n1, n2);
}

//
//create_mod_node
//
Modulus_Expr_Node * Calc_Node_Factory::create_mod_node(Expr_Node * n1, Expr_Node * n2)
{
	return new Modulus_Expr_Node(n1, n2);
}

//
//create_parentheses_node
//
Open_Parentheses_Node * Calc_Node_Factory::create_parentheses_node(void)
{
	return new Open_Parentheses_Node();
}

//
//create_empty_unary_node
//
Unary_Expr_Node * Calc_Node_Factory::create_empty_unary_node(void)
{
	return new Unary_Expr_Node();
}

//
//create_empty_add_node
//
Add_Expr_Node * Calc_Node_Factory::create_empty_add_node(void)
{
	return new Add_Expr_Node();
}

//
//create_empty_subtract_node
//
Subtract_Expr_Node * Calc_Node_Factory::create_empty_subtract_node(void)
{
	return new Subtract_Expr_Node();
}

//
//create_empty_multiply_node
//
Multiply_Expr_Node * Calc_Node_Factory::create_empty_multiply_node(void)
{
	return new Multiply_Expr_Node();
}

//
//create_empty_divide_node
//
Divide_Expr_Node * Calc_Node_Factory::create_empty_divide_node(void)
{
	return new Divide_Expr_Node();
}

//
//create_empty_modulus_node
//
Modulus_Expr_Node * Calc_Node_Factory::create_empty_modulus_node(void)
{
	return new Modulus_Expr_Node();
}
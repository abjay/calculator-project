
// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <algorithm>
//
// Stack
//
template <typename T>
Stack <T>::Stack(void)
	:ptr_(5), //Calling Array class template's constructor
	top_(-1),
	def_size_(5)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack(const Stack & stack)
	:ptr_(5),
	top_(-1),
	def_size_(5)
{
	for (size_t i = 0; i < stack.top_+1; i++)
	{
		//Calling Array template's get() method to get values from stack
		T val = stack.ptr_.get(i);
		//Calling Array template's set() method to set values into lhs
		ptr_.set(i, val);
	}
	top_ = stack.top_;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack(void)
{
	
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
  if ((this != &rhs) && (rhs.top_ != -1))
	{
		//Checking if the stack is already filled
		if (top_ != -1)
		{
			//Clearing stack in order to assign rhs elements
			clear();
		}
		for (size_t i = 0; i < rhs.top_+1; i++)
		{
			//Using get() method from Array template on rhs to push() items into lhs
			push(rhs.ptr_.get(i));
		}
		this->top_ = rhs.top_;
	}
	return *this;
}

//
// push
//
template <typename T>
void Stack <T>::push(T element)
{
	//Checking if default size has been reached
	if ((top_+1) >= def_size_)
	{
		def_size_ = def_size_ + 5;
		//Calling resize() in order to make sure the stack is never full
		ptr_.resize(def_size_);
	}
	top_++;
	//Calling set() method to push element into the stack
	ptr_.set(top_, element);
}

//
// pop
//
template <typename T>
void Stack <T>::pop(void)
{
	if (top_ == -1)
	{
		throw empty_exception();
	}
	//Popping element from stack
	top_--;
}

//
// clear
//
template <typename T>
void Stack <T>::clear(void)
{
	if (top_ == -1)
		return;
	top_ = -1;
}
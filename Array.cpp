// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <algorithm>

//
// Array
//
template <typename T>
Array <T>::Array(void)
	: cur_size_(0),
	max_size_(0),
	data_(0)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array(size_t length)
	: cur_size_(length),
	max_size_(length),
	data_(0)
{
	if (length == 0)
		return;
	//Creating a new array
	data_ = new T[cur_size_];
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array(size_t length, T fill)
	: data_(0),
	cur_size_(length),
	max_size_(length)
{
	if (length == 0)
		return;
	//Creating a new array
	data_ = new T[cur_size_];
	//for loop to fill elements in the array
	for (size_t i = 0; i < cur_size_; i++)
	{
		data_[i] = fill;
	}
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array(const Array & array)
	:data_(0),
	cur_size_(array.cur_size_),
	max_size_(array.max_size_)
{
	data_ = new T[cur_size_];
	//for loop to copy array.data_ elements into this->data_ array
	for (size_t i = 0; i < cur_size_; i++)
		this->data_[i] = array.data_[i];
}

//
// ~Array
//
template <typename T>
Array <T>::~Array(void)
{
	if (data_ != 0)
		delete[] data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	//Checking for self assignment
	if (this != &rhs){
		//Condition check to see if rhs array is bigger
		if (this->cur_size_ < rhs.cur_size_)
		{
			//Creating temporary array to store elements while copying
			T* re_array = new T[rhs.cur_size_];
			for (size_t i = 0; i < rhs.cur_size_; i++)
			{
				//Filling rhs array elements into temporary array
				re_array[i] = rhs.data_[i];
			}
			//Setting the limiting variables appropriately
			cur_size_ = rhs.cur_size_;
			max_size_ = rhs.max_size_;

			//Swapping the contents on temporary array and data_ array
			std::swap(re_array, data_);
			//Deleting temporary array
			delete[] re_array;
		}
		else //else block if rhs array is equal to or smaller
		{
			//Creating temporary array to store elements while copying
			T* re_array = new T[this->cur_size_];
			for (size_t i = 0; i < rhs.cur_size_; i++)
			{
				//Filling rhs array elements into temporary array
				re_array[i] = rhs.data_[i];
			}
			//Setting the limiting variables appropriately
			cur_size_ = rhs.cur_size_;
			//Swapping the contents on temporary array and data_ array
			std::swap(re_array, data_);
			//Deleting temporary array
			delete[] re_array;
		}
	}
	return *this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if (index >= cur_size_)
	{
		throw std::out_of_range("Invalid index value");
	}
	//Returning the data at the index
	return this->data_[index];

}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	//Returning the data at the index
	return this->data_[index];
}

//
// get
//
template <typename T>
T Array <T>::get(size_t index) const
{
	if (index >= cur_size_)
	{
		throw std::out_of_range("Invalid index value");
	}
	//Returning the data at the index
	return this->data_[index];
}

//
// set
//
template <typename T>
void Array <T>::set(size_t index, T value)
{
	if (index >= cur_size_)
	{
		throw std::out_of_range("Invalid index value");
	}
	//Returning the data at the index
	this->data_[index] = value;
}

//
// resize
//
template <typename T>
void Array <T>::resize(size_t new_size)
{
	//Checking for same size
	if (new_size == max_size_)
	{
		return;
	}
	//Checking if the new size is smaller than max_size_ but larger than or equal to cur_size_
	if ((new_size < max_size_) && (new_size >= cur_size_))
	{
		//Setting the appropriate value of max_size_
		max_size_ = new_size;
		return;
	}
	else if ((new_size < max_size_) && (new_size < cur_size_)) //Checking if the new size is smaller than max_size_ and cur_size_
	{
		//Setting the variables appropriately
		cur_size_ = new_size;
		max_size_ = new_size;
		//Creating temporary array to store elements
		T* re_array = new T[cur_size_];
		for (size_t i = 0; i < cur_size_; i++)
		{
			//Storing array elements into temporary array
			re_array[i] = this->data_[i];
		}
		//Swapping the contents of temporary array and original array
		std::swap(re_array, data_);
		//Deleting temporary array
		delete[] re_array;
	}
	else if (new_size > max_size_) //Checking if new size is larger than max_sze_
	{
		//Creating temporary array to store elements
		T* re_array = new T[new_size];
		for (size_t i = 0; i < cur_size_; i++)
		{
			//Storing array elements into temporary array
			re_array[i] = this->data_[i];
		}
		//Swapping the contents of temporary array and original array
		std::swap(re_array, data_);
		delete[] re_array;
		//Setting the variables appropriately
		max_size_ = new_size;
		//Eliminating garbage values in the resized array
		for (size_t i = cur_size_; i < new_size; i++)
			this->data_[i] = 0;
		cur_size_ = new_size;
		return;
	}
}

//
// find (char)
//
template <typename T>
int Array <T>::find(T ch) const
{
	//for loop to traverse through array elements
	for (size_t i = 0; i < cur_size_; i++)
	{
		//Condition to find the required character
		if (data_[i] == ch)
			return i;
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find(T ch, size_t start) const
{
	if (start >= cur_size_)
	{
		throw std::out_of_range("Invalid index value");
	}
	//for loop to traverse through array elements
	for (size_t i = start; i < cur_size_; i++)
	{
		//Condition to find the required character
		if (data_[i] == ch)
			return i;
	}
	return -1;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	for (size_t i = 0; i < cur_size_; i++)
	{
		//Checking if both the arrays are equal
		if (this->data_[i] != rhs.data_[i])
			return false;
	}
	return true;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array <T>::fill(T ch)
{
	for (size_t i = 0; i < cur_size_; i++)
	{
		this->data_[i] = ch;
	}
}
// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return this->top_+1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if (top_ == -1)
	{
		throw empty_exception();
	}
	return ptr_[top_];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if (top_ == -1)
		return true;
	else
		return false;
}

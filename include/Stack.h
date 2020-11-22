#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include "Vector.h"

template <class T>

class Stack : protected Vector <T>
{
public:
	Stack() : Vector() {}
	Stack(int length) : Vector(length) {}
	Stack(const Stack &s) : Vector(s) {}
	~Stack() {}
	bool empty()
	{
		if (top == 0)
			return true;
		return false;
	}
	bool full()
	{
		if ((top != 0) && (top == len))
			return true;
		return false;
	}
	void push(T elem)
	{
		push_back(elem);
	}
	void pop()
	{
		pop_back();
	}
	bool operator==(const Stack &s) const
	{
		if ((top != s.top) || (len != s.len)) return false;
		for (int i = 0; i < top; i++)
		{
			if (data[i] != s.data[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator!=(const Stack &s) const
	{
		if (&s == this) return false;
		return true;
	}
};

#endif
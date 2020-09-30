#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

template <class T>

class Vector
{
	T* data;
	int len;
	int top = 0;
public:
	Vector()
	{
		len = 20;
		data = new T[len];
	}
	Vector(int length)
	{
		len = length;
		data = new T[len];
	}
	Vector(const Vector& v)
	{
		data = v.data;
		len = v.len;
		top = v.top;
	}
	~Vector()
	{
		delete[] data;
	}
	void push_back(T elem)
	{
		if (top == len - 1)
			resize();
		data[top] = elem;
		top++;
	}
	void pop_back()
	{
		if (empty()) throw "Vector is empty!";
		top--;
	}
	void resize(int newlen = len * 2)
	{
		T* temp = new T[newlen];
		for (int i = 0; i < len; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		len = newlen;
		delete[] temp;
	}
	bool empty()
	{
		if (top == 0)
			return true;
		return false;
	}
	void push_front(T elem)
	{
		if (top == len - 1)
			resize();
		T* temp = new T[len];
		for (int i = 0; i < top; i++)
			temp[i + 1] = data[i];
		temp[0] = elem;
		delete[] data;
		data = temp;
		top++;
		delete[] temp;
	}
	void pop_front()
	{
		if (empty()) throw "Vector is empty!";
		T* temp = new T[len];
		for (int i = 1; i < top; i++)
			temp[i - 1] = data[i];
		delete[] data;
		data = temp;
		delete[] temp;
		top--;
	}
	T& operator[](int index)
	{
		return *this->data[index];
	}
};


#endif

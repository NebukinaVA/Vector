#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

//const int MAX_SIZE = 10000;

template <class T>
class Vector
{
protected:
	T* data;
	int len;
	int top = 0;
public:
	// ����������� �� ���������
	Vector()
	{
		len = 20;
		data = new T[len];
	}
	// ����������� � ����������
	Vector(int length)
	{
		if (length < 0) throw "Incorrect input.";
		len = length;
		data = new T[len];
	}
	// ����������� �����������
	Vector(const Vector &v)
	{
		len = v.len;
		top = v.top;
		data = new T[len];
		for (int i = 0; i < top; i++)
			data[i] = v.data[i];
	}
	// ����������
	virtual ~Vector()                
	{
		delete[] data;
	}
	// �������� ������� � ����� �������
	void push_back(T elem)
	{
		if (top == len)
		{
			if (len == 0)
				resize(20);
			else resize();
		}
		data[top] = elem;
		top++;
	}
	// ������� ��������� ������� �������
	void pop_back()
	{
		if (empty()) throw "Vector is empty!";
		top--;
	}
	// ����������� � ����������
	void resize(int newlen)
	{
		if (newlen < len) throw "New length is less than old length";
		T* temp = new T[newlen];
		for (int i = 0; i < len; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		len = newlen;
	}
	// ����������� ��� ���������
	void resize()
	{
		int newlen = len * 2;
		if (len == 0) newlen = 10;
		T* temp = new T[newlen];
		for (int i = 0; i < len; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		len = newlen;
	}
	// ���������, ������ �� ������
	bool empty()
	{
		if (top == 0)
			return true;
		return false;
	}
	// ������� ������ �������
	size_t size()
	{
	//	return static_cast<size_t>(len);
    	return static_cast<size_t>(top);
	}
	// �������� ������ � ������ �������
	void push_front(T elem)
	{
		if (top == len)
		{
			if (len == 0)
				resize(20);
			else resize();
		}
		for (int i = top - 1; i >= 0; i--) 
			data[i + 1] = data[i];
		data[0] = elem;
		top++;
	}
	// ������� ������ ������� �������
	void pop_front()
	{
		if (empty()) throw "Vector is empty!";
		for (int i = 1; i < top; i++)
			data[i - 1] = data[i];
		top--;
	}
	// ���������� ��������� [] � ������������� ��������
	T& operator[](int index)
	{
		if ((index < 0) || (index >= len)) throw "Incorrect index!";
		return this->data[index];
	}
	// ���������� ��������� [] � ����������� ��������
	const T& operator[](int index) const
	{
		if ((index < 0) || (index >= top)) throw "Incorrect index!";
		return this->data[index];
	}
	// ���������� ��������� ���������
	bool operator==(const Vector &v) const
	{
		if ((top != v.top) || (len != v.len)) return false;
		for (int i = 0; i < top; i++)
		{
			if (data[i] != v.data[i])
			{
				return false;
			}
		}
		return true;
	}
	// ���������� ��������� ���������
	bool operator!=(const Vector &v) const   
	{
		if (&v == this) return false;
		return true;
	}
	// ���������� ��������� ������������
	Vector<T>& operator=(const Vector &v)
	{
		if (&v != this)
		{
			if ((len != v.len) || (top != v.top))
			{
				top = v.top;
				len = v.len;
				delete[] data;
				data = new T[len];
			}
			for (int i = 0; i < top; i++)
				data[i] = v.data[i];
		}
		return *this;
	}
};


#endif

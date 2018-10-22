#include"Stack.h"
#include<iostream>

Stack::Stack()
{
	size = initialSize;
	members = new double[size];
	top = -1;
}

Stack::~Stack()
{
	delete[] members;
}

void Stack::push(double num)
{
	if (top == size - 1)
	{
		grow();
	}
	members[++top] = num;
}

double Stack::pop()
{
	if (empty())
	{
		std::cout << "stack underflow" << std::endl;
		return 0;
	}
	double num = members[top];
	top--;
	return num;
}

double Stack::peek() const
{
	if (empty())
	{
		std::cout << "stack underflow" << std::endl;
		return 0;
	}
	return members[top];
}

bool Stack::empty() const
{
	return (top == -1);
}

void Stack::grow()
{
	double * newArr = new double[size * 2];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = members[i];
	}
	size *= 2;
	delete[] members;
	members = newArr;
}
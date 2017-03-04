#include "STACK.h"
#include <stdio.h>
#include <iostream>
#include <assert.h>

#define ASSERT_OK()			\
if (!ok())					\
{							\
	dump();					\
	assert(!"Object is OK");\
}							

typedef float value_type;
using namespace std;
static const int POISON = 111222;

Stack::Stack()
{
	size = 0;
	for (int i = 0; i < CAPACITY; i++)
	{
		data[i] = 0;
	}
}
Stack::~Stack()
{
	size = POISON;
	for (size_t i = 0; i < CAPACITY; i++)
	{
		data[i] = POISON;
	}
}

value_type Stack::pop() //дописать случай сайза=0
{
	ASSERT_OK();
	return data[this->size--];
}

bool Stack::push(value_type value)
{
	ASSERT_OK();
	if (size >= CAPACITY)
	{
		ASSERT_OK();
		return false;
	}
		
	else
	{
		data[this->size++] = value;
		ASSERT_OK();
		return true;
	}
}

void Stack::dump()
{
	cout <<"capacity: "<< CAPACITY << endl;
	cout << "head " << size << endl;
	cout << "data[]:" << endl << "{" << endl;
	for (size_t i = 0; i < CAPACITY; i++)
	{
		if (i < size)
			cout << "	**[" << i << "]" << " = " << data[i] << endl;
		else
			cout << "	[" << i << "]" << " = " << data[i] << endl;
	}
	cout << "}" << endl;
}

bool Stack::ok()
{
	if (size > CAPACITY)
		return false;
	else
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			if (data[i] == POISON)
				return false;
			else
				return true;
		}
	}
}

size_t Stack :: capacity()
{
	ASSERT_OK();
	return size;
}

value_type Stack::GetLast()
{
	return data[size];
}
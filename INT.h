#pragma once
#include "Print.h"
class Int
{
public:
	Int();
	Int(int number);
	int number_;
const Int& operator+(const Int& L)
	{
		number_ = L.number_ + number_;
		return *this;
	}

	const Int& operator == (const Int& that)
	{
		number_ = that.number_;
		return *this;
	}
	
	const Int& operator-(const Int& L)
	{
		number_ = number_ - L.number_;
		return *this;
	}
	

	
private:
	
	

	
};

#include "Massive.h"
#include <assert.h>

#define ASSERT_OK()			\
if (!ok())					\
{							\
	dump();					\
	assert(!"Object is OK");\
}	

typedef float value_type; // Elements type

static const value_type POISON = NAN;




Massive::Massive()
{
	size_ = 10;
	data_ = new value_type[10];
	for (size_t i = 0; i < size_; i++)
		data_[i] = 0;
	std::cout << "Constructor without parametres was called" << endl;
	dump();
}

 Massive::Massive(size_t size)
{
	data_ = new value_type[size];
	size_ = size;
	for (size_t i = 0; i < size_; i++)
		data_[i] = 0;
	std::cout << "Constructor with parametr was called" << endl;
	dump();
}


Massive::~Massive()
{
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = POISON;
		size_ = POISON;
	}
	delete[] data_;

	std::cout << "Distructor was called" << endl;
	dump();
}


Massive::Massive(const Massive& that)
{
	ASSERT_OK();
	

	size_ = that.size_;
	data_ = new value_type[that.size_];

	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = that.data_[i];
	}

	std::cout << "Copy was called" << endl;
	dump();
}


void Massive::ReSize(size_t newsize)
{
	ASSERT_OK();
	Massive t(newsize);
	//size_t p = newsize > size_ ? size_ : newsize;
	if (newsize > size_)
		{
			for (size_t i = 0; i < size_; i++)
			{
				t.data_[i] = data_[i];
			}
			for (size_t i = size_; i < newsize; i++)
			{
				t.data_[i] = 0;
			}
		}
	else
		{
			for (size_t i = 0; i < newsize; i++)
			{
				t.data_[i] = data_[i];
			}
		}
	delete[] data_;
	data_ = new value_type[newsize];
	for (size_t i = 0; i < newsize; i++)
	{
		data_[i] = t.data_[i];
	}

	std::cout << "Function Resize was called" << endl;
	dump();
}

void Massive::dump()
{
	std::cout << "Masssive's name: " << data_ << endl;
	std::cout << "size: " << size_ << endl;

	for (size_t i = 0; i < size_; i++)
		std::cout << "[" << i << "] = " << data_[i] << endl;
}


size_t Massive::Size()
{
	ASSERT_OK();
	std::cout << "Function Size was called" << endl;
	dump();
	return size_;
}


value_type Massive::GetEl(size_t i) const
{
	return data_[i];
}


//---------------------------
//!Check the mass
//---------------------------

bool Massive::ok()
{
	for (size_t i = 0; i < size_; i++)
		if (this->GetEl(i) == POISON || this->size_ == POISON)
			return false;
	return true;
}
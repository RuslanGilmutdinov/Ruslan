#pragma once
#include <iostream>

//-----------------------------
//! @file Massive.h
//! Implements a massive class
//!
//! @author Ruslan, 2017
//-----------------------------

//-----------------------------
//! Massive class
//-----------------------------


using namespace std;
class Massive
{
public:
	typedef float value_type; //!< Elements type
//---------------------------
//!A constructor
//---------------------------
	Massive(); 
//---------------------------
//!A constructor with parametres
//---------------------------
 Massive(size_t size);
//---------------------------
//! A destructor
//---------------------------
	~Massive();

//---------------------------
//!Return a size of the massive
//---------------------------
	size_t Size();
//---------------------------
//!Return an element with index = i
//---------------------------
	value_type GetEl(size_t i) const;
	
//---------------------------
//!Changes a size of the massive
//---------------------------
	void ReSize(size_t newsize);
//---------------------------
//!Print dump
//---------------------------
	void dump();
//---------------------------
//!Check the massive
//---------------------------
	bool ok();
//---------------------------
//!Copy metod
//---------------------------
	Massive(const Massive& that);

	const Massive& operator = (const Massive&R)
	{
		if (this != &R)
		{
			
			delete[] data_;
			size_ = R.size_;
			data_ = new value_type[size_];
			for (size_t i = 0; i < size_; i++)
				data_[i] = R.data_[i];
		}
		std::cout << "Operator =  was called" << endl;
		dump();
		return *this;
	}
	
private:
	size_t size_;
	value_type* data_;
	
	
	
};
#include "INT.h"
#include <iostream>
#include <conio.h>
#include "Massive.h"

using namespace std;

int main()
{

	/*Int a(3);
	Int c(4);
	Int d;
	d == a + c;
	*/
	//PRINT_(d.number_);
	
	//cout << d.number_ << endl;
	
	Massive A(10);
	Massive B(5);
	Massive C(B);
	C = A;
	Massive D;
	D = A;
	


	_getch();
	
}


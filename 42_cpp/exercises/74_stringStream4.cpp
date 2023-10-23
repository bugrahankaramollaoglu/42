#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	// Numeric to string
	stringstream ss;

	int nInt = 2019;
	double nDouble = 3.142;
	ss << nInt << " " << nDouble;

	string myStr1, myStr2;
	ss >> myStr1 >> myStr2;

	cout << "The numeric values converted to string:" << endl;
	cout << "myStr1 = " << myStr1 << "\n"
		 << "myStr2 = " << myStr2 << endl;
		 
	// string to numeric
	stringstream ns;
	ns << "2019 3.142"; // insert a string of numbers into the stream
	int nIntval;
	double nDoubleval;

	ns >> nIntval >> nDoubleval;
	cout << "The string values converted to numeric types:" << endl;
	cout << "nIntval = " << nIntval << "\n"
		 << "nDoubleval = " << nDoubleval << endl;
}

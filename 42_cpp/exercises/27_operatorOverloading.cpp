#include <iostream>

/* built-in veri tiplerini toplayabiliriz mesela bir int ile
bir double. ama bir class'ın iki objesini toplayamayiz çünkü
veri tipleri className'dir yani user-defined. o yüzden +, - vs.
operatörleri overload etmemiz gerekir */

/* Now, if the user wants to make the operator “+” add two class objects,
the user has to redefine the meaning of the “+” operator such that
it adds two class objects. */

class Complex
{
private:
	int real, imag;

public:
	Complex(int r = 0, int i = 0)
	{
		real = r;
		imag = i;
	}

	// operator function overloading
	// className operatorFuncName_operatorSign(className &obj)
	Complex operator+(Complex const &obj)
	{
		Complex result;
		result.real = real + obj.real;
		result.imag = imag + obj.imag;
		return result;
	}
	void print()
	{
		std::cout << real << " + i" << imag << "\n";
	}
};

int main() {
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
	c3.print();
}

#include <iostream>

/* built-in veri tiplerini toplayabiliriz mesela bir int ile
bir double. ama bir class'ın iki objesini toplayamayiz çünkü
bu veri tipleri user-defined tiplerdir. o yüzden +, - vs. gibi
operatörleri pnları toplayip cikaracak sekilde overload etmemiz gerekir */

class Deneme
{
public:
	int myVal;

	Deneme(int val = 0) : myVal(val)
	{
	}

	const Deneme operator+(const Deneme &other)
	{
		return Deneme(myVal + other.myVal);
	}
};

int main()
{
	Deneme num1(10);
	Deneme num2(20);

	Deneme sum = num1 + num2;

	std::cout << sum.myVal << std::endl; // 30
	// burada sadece sum diyemiyoruz çünkü bir class objesi direkt << ile
	// yazdırılabilir değil, <<'i de overload etmemiz gerek.
}

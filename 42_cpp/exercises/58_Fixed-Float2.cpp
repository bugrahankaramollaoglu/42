#include <iostream>

// give me 10 exercises ranging from easy to hard so
// that I can understand fixed and floating point of numbers,
// prefer c++ if you are going to use code - chatgpt

/* Exercise 2 (Easy):
Write a C++ program that declares a floating-point variable,
initializes it with a value, and prints it to the console. */

int main() {
	float a = 2.45f;
	std::cout << a << std::endl;
}

/* 32.66 demekle 32.66f demek arasında fark vardır.
eğer suffix olmadan direkt 32.66 dersek cpp bunu float
değil double olarak algılar, double da daha fazla
precisiona sahiptir. genelde 64 bit.
sonuna f koydugun sayilar ise float olarak algılanır.  */

void fun2() {
	float a = 32.66f;
	std::cout << a << std::endl;
}

/* Exercise 6 (Intermediate):
Write a C++ program that converts a decimal integer
into its binary representation. */

// there are 2 ways to convert from decimal to binary
// one is by constantly dividing by 2 and putting 1
// every time remainder is 1 put 1 as binary, 0 for 0
void fun6(int nb) {
	char *bin = new char[9];
	int i = 0;

	for (int i = 0; i < 8; i++)	{
		bin[i] = '0';
	}

	while (nb > 0 && i < 8) {
		bin[7 - i] = (nb % 2) + 48;
		nb /= 2;
		i++;
	}

	bin[8] = '\0';
	std::cout << bin << std::endl;
	delete bin;
}

/* Exercise 7 (Intermediate):
Write a C++ program that converts a binary string
(e.g., "1010") into its decimal equivalent. */

#include <string>
#include <algorithm>

void fun7(std::string bin) {
	int nb(0);
	int i = 0;
	std::reverse(bin.begin(), bin.end());
	for (int x = 0; x < bin.length(); x++) {
		if (bin[x] == '1') {
			// nb += pow(2, x);
			// pow() involves float-point arithmetic
			// which may cause rounding errors for large
			// value of x. use that instead
			nb |= (1 << x);
		}
	}
	std::cout << nb << "\n";
}



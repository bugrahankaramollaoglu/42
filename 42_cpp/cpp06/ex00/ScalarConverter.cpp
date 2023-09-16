/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:12:37 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/12 18:33:46 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &org)
{
	*this = org;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	if (this == &other)
	{
		*this = other;
	}
	return *this;
}

bool ScalarConverter::isStringEqual(const std::string &str)
{
	const std::string arr[] = {
		"nan",
		"nanf",
		"+inf",
		"-inf",
		"+inff",
		"-inff"};

	for (int i = 0; i < 6; i++)
	{
		if (str == arr[i])
			return true;
	}
	return false;
}

void ScalarConverter::checkValue(const std::string &str)
{
	if (!isStringEqual(str) && str.length() != 1)
	{
		// eğer bunlardan hariç bir karakter içeriyosa
		const std::string allowedCharacters = "0123456789.f-+";
		for (char c : str)
		{
			if (allowedCharacters.find(c) == std::string::npos)
			{
				std::cerr << "it is not convertable" << std::endl;
				exit(2);
			}
		}
	}
	if (str.find(".") != std::string::npos)
	{
		// find() returns the first position of found-item
		// if it cannot find the item, it returns 0
		size_t d = str.find(".");
		// .442, 34.53.60 ya da 34. gibi kullanımlarda hata verdiriyoruz
		if (d == 0 || d != str.find_last_of(".") || d == str.length() - 1)
		{
			std::cerr << ("wrong dot usage") << std::endl;
			exit(3);
		}
	}
	if (str.find("f") != std::string::npos)
	{
		size_t f = str.find("f");
		// f324, 34f532f ya da 34.f gibi durumda hata
		if ((f == 0 || f != str.find_last_of("f") || str[f - 1] == '.') && str.length() != 1)
		{
			std::cerr << ("wrong f usage") << std::endl;
			exit(4);
		}
	}
	// + ya da - varsa
	if ((str.find("+") != std::string::npos) || (str.find("-") != std::string::npos))
	{
		// birden fazla ++ ya da -- olmamalı
		if (str.find("-") != str.find_last_of("-") || str.find("+") != str.find_last_of("+"))
		{
			std::cerr << ("multiple +/- not allowed") << std::endl;
			exit(5);
		}
		int a = str.find("-");
		if (a == 0 || a == 1)
		{
			if (str[a + 1] == '+' || str[a - 1] == '+')
			{
				std::cerr << ("+- or -+ not allowed") << std::endl;
				exit(6);
			}
		}
	}
}

int ScalarConverter::checkRange(std::string type, std::string str)
{
	int i = 0;
	if (type == "char" || type == "int")
	{
		try
		{
			// stoi atoi'nin c++ karşılığı
			i = std::stoi(str);
		} // eğer çevrilemeyecek bir şeyse karşılık olarak impossible yazdiriyoruz
		catch (const std::exception &e)
		{
			std::cout << type + ": impossible" << std::endl;
			return -1;
		}
	}
	else if (type == "float")
	{
		try
		{
			std::stof(str);
		}
		catch (const std::exception &e)
		{
			std::cout << type + ": impossible" << std::endl;
			return -1;
		}
	}
	else if (type == "double")
	{
		try
		{
			std::stod(str);
		}
		catch (const std::exception &e)
		{
			std::cout << type + ": impossible" << std::endl;
			return -1;
		}
	}
	return i;
}

void ScalarConverter::convert(const std::string &str)
{
	toChar(str);
	toInt(str);
	toFloat(str);
	toDouble(str);
}

void ScalarConverter::toChar(const std::string &str)
{
	char c;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	// ./convert a b 'c' '*' vs. buna girer
	if (str.length() == 1)
	{
		c = str.at(0);
		std::cout << "char: '" << c << "'" << std::endl;
		return;
	}
	int i = checkRange("char", str);
	if (i != -1 && (i < 32 || i > 127)) // eğer printable değilse
	{
		std::cout << "char: not displayable" << std::endl;
		return;
	}
	// ./convert 99 (c) 120 115 vs. buna girer çünkü onlar da char ama len!=1
	if (i != -1)
	{
		c = static_cast<char>(i);
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

void ScalarConverter::toInt(const std::string &str)
{
	int i;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "int : impossible" << std::endl;
		return;
	}
	if (str.length() == 1)
	{
		// eğer isdigit() 0 döndürüyosa yani sayı rakam değilse
		// karakterdir ve inte çevrilebilir. mesela ./convert 'b'
		// ifadesinde buna girer ve int karşılığı olan 98 yazdirilir
		if (isdigit(str[0]) == 0)
			i = static_cast<int>(str[0]);
		// yok eğer rakamsa ./convert 5 gibi direkt çevrilip yazdirilir
		else
			i = std::stoi(str);
		std::cout << "int: " << i << std::endl;
		return;
	}
	i = checkRange("int", str);
	if (i != -1)
		std::cout << "int: " << std::stoi(str) << std::endl;
}

void ScalarConverter::toFloat(const std::string &str)
{
	float f;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "float: " << str << "f" << std::endl;
		return;
	}
	if (str.length() == 1)
	{
		if (isdigit(str[0]) == 0)
			f = static_cast<float>(str[0]);
		else
			f = std::stof(str);
		std::cout << "float: " << f << "f" << std::endl;
		return;
	}
	int i = checkRange("float", str);
	if (i != -1)
	{
		f = std::stof(str);
		if (f - static_cast<int>(f) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
}

void ScalarConverter::toDouble(const std::string &str)
{
	double d;
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "double: " << str << std::endl;
		return;
	}
	if (str.length() == 1)
	{
		if (isdigit(str[0]) == 0)
			d = static_cast<double>(str[0]);
		else
			d = std::stod(str);
		std::cout << "double: " << d << std::endl;
		return;
	}
	int i = checkRange("double", str);
	if (i != -1)
	{
		d = std::stod(str);
		if (d - static_cast<int>(d) == 0)
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
}

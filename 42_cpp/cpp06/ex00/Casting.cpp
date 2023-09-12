#include "Casting.hpp"

Casting::Casting()
{
}

Casting::~Casting()
{
}

Casting::Casting(Casting const &org)
{
	*this = org;
}

Casting &Casting::operator=(Casting const &other)
{
	if (this == &other) {
		*this = other;
	}
	return *this;
}

bool Casting::isStringEqual(const std::string& str)
{
    const std::string arr[] = {
        "nan",
        "nanf",
        "+inf",
        "-inf",
        "+inff",
        "-inff"
    };

const int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
	{
        if (str == arr[i])
    	    return true;
	}
    return false;
}

void Casting::checkValue(const std::string &str)
{
	
	if (!isStringEqual(str) && str.length() != 1)
	{
		if (str.find_first_not_of("0123456789.f-+") != std::string::npos)
		{
			std::cerr << "The value you entered is not something I can convert." << std::endl;
			exit(2);
		}
	}
	if(str.find(".") != std::string::npos)
	{
		size_t d = str.find(".");
		if (d == 0 || d != str.find_last_of(".") || d == str.length() - 1)
		{
			std::cerr << ("The use of the dot in the entered value is incorrect.") << std::endl;
			exit(3);
		}
	}
	if (str.find("f") != std::string::npos)
	{
		size_t f = str.find("f");
		if ((f == 0 || f != str.find_last_of("f") || str[f-1] == '.') && str.length() != 1)
		{
			std::cerr << ("The use of the f in the entered value is incorrect.") << std::endl;
			exit(4);
		}
	}
	if ((str.find("+") != std::string::npos) || (str.find("-") != std::string::npos))
	{
		if (str.find("-") != str.find_last_of("-") || str.find("+") != str.find_last_of("+"))
		{
			std::cerr << ("You should not use more than one + or - sign.") << std::endl;
			exit(5);
		}
		int a = str.find("-");
		if(a == 0 || a == 1)
		{	
			if (str[a + 1] == '+' || str[a - 1] == '+')
			{
				std::cerr << ("You should not use like that.") << std::endl;
				exit(6);
			}
		}
	}
}

int Casting::checkRange(std::string type, std::string str)
{
	int i = 0;
	if (type == "char" || type == "int")
	{
		try
		{
			i = std::stoi(str);
		}
		catch(const std::exception& e)
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
		catch(const std::exception& e)
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
		catch(const std::exception& e)
		{
			std::cout << type + ": impossible" << std::endl;
			return -1;
		}
	}
	return i;
}

void Casting::convert(const std::string &str)
{
    toChar(str);
    toInt(str);
    toFloat(str);
    toDouble(str);
}

void Casting::toChar(const std::string &str)
{
	char c;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "char : impossible" << std::endl;
		return ;
	}
	if (str.length() == 1)
	{
		c = str[0];
		std::cout << "char: '" << c << "'" << std::endl;
		return ;
	}
	int i = checkRange("char", str);
	if (i != -1 && (i < 32 || i > 127))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	if (i != -1)
	{
		c = static_cast<char>(i);
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

void Casting::toInt(const std::string &str)
{
	int i;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "int : impossible" << std::endl;
		return ;
	}
	if (str.length() == 1)
	{
		if (isdigit(str[0]) == 0)
			i = static_cast<int>(str[0]);
		else
			i = std::stoi(str);
		std::cout << "int: " << i << std::endl;
		return ;
	}
	i = checkRange("int", str);
	if (i != -1)
		std::cout << "int: " <<  std::stoi(str) << std::endl;
}

void Casting::toFloat(const std::string & str)
{
	float f;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "float: " << str << "f" << std::endl;
		return ;
	}
	if (str.length() == 1)
	{
		if (isdigit(str[0]) == 0)
			f = static_cast<float>(str[0]);
		else
			f = std::stof(str);
		std::cout << "float: " << f << "f" << std::endl;
		return ;
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

void Casting::toDouble(const std::string & str)
{
	double d;
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
	{
		std::cout << "double: " << str << std::endl;
		return ;
	}
	if (str.length() == 1)
	{
		if (isdigit(str[0]) == 0)
			d = static_cast<double>(str[0]);
		else
			d = std::stod(str);
		std::cout << "double: " << d << std::endl;
		return ;
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

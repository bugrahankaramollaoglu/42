#include <string>
#include <iostream>

class Student
{
private:
	std::string _login;

public:
	Student() : _login("defaultName")
	{
		std::cout << "Student " << this->_login << " is born" << std::endl;
	}

	~Student()
	{
		std::cout << "Student " << this->_login << " died" << std::endl;
	}
};

int main()
{
	Student *students = new Student[5]; // new() does not take parameters

	delete[] students;
}

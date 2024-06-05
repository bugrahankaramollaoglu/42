#include <iostream>
#include <string>

/* mallocing an object does not work in C++, because it does
not call the constructor of the object.
Similarly, if you free() an object, it also won't call the
destructor new() and delete() */

/* using static allocation allocates space on stack segment of ram. stack has a limited
space of about 2gb. heapten hemen her zaman daha sağlıklıdır, prefer this one whenever you can. */

class Student
{
private:
	std::string _login;

public:
	Student(std::string login) : _login(login)
	{
		std::cout << "Student " << this->_login << " is born"
				  << "\n";
	}
	~Student()
	{
		std::cout << "Student " << this->_login << " died"
				  << "\n";
	}
};

int main()
{
	Student s1 = Student("ahmet");		 // allocated on stack
	Student *s2 = new Student("mehmet"); // allocated on heap

	delete s2;
}

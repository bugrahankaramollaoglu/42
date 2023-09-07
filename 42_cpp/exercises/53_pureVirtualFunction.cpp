#include <iostream>

class Shape
{
public:
	virtual double area() = 0; // Pure virtual function
	virtual void displayInfo() // not PVF
	{
		// Some default implementation
	}
};

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double r) : radius(r) {}

	double area() override
	{
		return 3.14159 * radius * radius;
	}
};

class Rectangle : public Shape
{
private:
	double width, height;

public:
	Rectangle(double w, double h) : width(w), height(h) {}

	double area() override
	{
		return width * height;
	}
};

int main()
{
	Circle circle(5.0);
	Rectangle rectangle(4.0, 6.0);

	Shape *shapes[] = {&circle, &rectangle};

	for (Shape *shape : shapes)
	{
		shape->displayInfo();
		std::cout << "Area: " << shape->area() << std::endl;
	}

	return 0;
}

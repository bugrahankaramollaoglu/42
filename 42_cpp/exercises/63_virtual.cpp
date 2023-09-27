#include <iostream>
using namespace std;

// when you declare a member method as virtual
// derived classes can override that function
// it is the way to achieve polymorphism
// without virtual, the code is determined compile-time
// with virtual, it is rendered runtime (66-67.cpp)

class Shape {
	public:
		virtual void sayWhat() {
			cout << "this is shape" << endl;
		}
};

class Rectangle : Shape {
	public:
		void sayWhat() override {
			cout << "this is rectangle" << endl;
		}
};

int main() {
	Shape shape;
	Rectangle rectangle;
	shape.sayWhat();
	rectangle.sayWhat();
}

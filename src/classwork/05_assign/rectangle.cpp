#include "rectangle.h"
//Write include statement


/*
Write the class function code for the Rectangle class with one constructor that accepts two int parameters (width, height),
has one public function area that returns the area of the rectangle, and one private function calculate_area
that calculates area of the rectangle.  The class has 3 int private variables area, width, and height.
*/

void Rect::calculate_area()
{
	area = width * height;


}

std::ostream & operator<<(std::ostream & out, const Rect & a)
{
	out << "Area is: " << a.area;
	// TODO: insert return statement here
	return out;
}
/*
std::istream & operator>>(std::istream & in, Rect & b)
{
	int amount;
	std::cout << "Enter amount: ";
	in >> amount;
	b.deposit(amount);
	// TODO: insert return statement here
	return in;
}
*/

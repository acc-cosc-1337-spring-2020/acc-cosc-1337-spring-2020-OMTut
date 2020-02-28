/*
Create the interface for a Rectangle class with one constructor that accepts two int parameters (width, height),
has one public function area that returns the area of the rectangle, and one private function calculate_area
that calculates area of the rectangle.  The class has 3 int private variables area, width, and height.
*/
#include <string>

class Rect
{
public:
	Rect(int w, int h) : width{ w }, height{ h } {calculate_area(); }
	int get_area()const { return area; }

private:
	int width;
	int height;
	int area;
	void calculate_area();
};
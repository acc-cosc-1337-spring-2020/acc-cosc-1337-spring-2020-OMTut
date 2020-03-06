//write include statemetns
#include "rectangle.h"
#include <iostream>
#include <vector>

using std::cout;
/*
Create a vector of rectangles
Add 3 Rectangle classes to the vector:
Width	Height		Area
  4		 5			  20
 10		10			 100
100		10			1000
Iterate the vector and display the Area for each Rectangle on one line and the total area for the
3 rectangles.
*/
int main()
{
	int totalarea{ 0 };

	std::vector<Rect> rectangles{ Rect(4,5), Rect(10,10), Rect(100,10) };

	for (auto r : rectangles)
	{
		totalarea += r.get_area();
		
		
		cout << r << "\n";
		
	}
	cout << totalarea;



	return 0;
}
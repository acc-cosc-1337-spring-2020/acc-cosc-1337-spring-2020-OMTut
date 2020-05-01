#include "vector.h"
#include<iostream>
/*
Initialize nums to size dynamic array.
Initialize eah array element to 0.
*/
Vector::Vector(size_t sz)
	: size {sz}, nums{new int[sz]} //this creates the dynamic array
{
	for (size_t i = 0; i < sz; ++i) //this iterates the new int [sz] array objects to 0
	{
		nums[i] = 0;
	}
}

/*
Copy v.size to new class
Create new dynamic memory array
Initialize array elements to the v.nums array values
*/
Vector::Vector(const Vector & v)
	: size{ v.size }, nums{ new int[v.size] } //this creates dynamic array based on the size in line 8
{
	for (size_t i = 0; i < size; ++i)
	{
		nums[i] = v[i]; //this sets i to whatever vi is.
	}
}

void Vector::Reserve(size_t new_allocation)
{

}

/*Release Dynamic memory - Deallocate memory*/
Vector::~Vector()
{
	std::cout << "\nrelease memory\n";
	delete[] nums;
}

//-----------------
//free function
void use_vector()
{
	Vector* v1 = new Vector(3);
	delete v1;
	v1 = nullptr;
}

Vector get_vector()
{
	Vector v(3);

	return v;
}
/*
Get the dynamic memory from v
Get the size from v
Point the v.nums to nullptr to take care of memory issue
*/
//////////////////////Move Constructor
Vector::Vector(Vector && v)
	: size{ v.size }, nums{v.nums}
{
	v.size = 0;
	v.nums = nullptr;
}

/*
Deallocate original dynamic memory
Get the dyanmic memory and size from v
Point v.nums to null ptr
Set v.size to 0
*/

Vector & Vector::operator=(Vector && v)
{
	delete nums;
	nums = v.nums;
	size = v.size;
	v.nums = nullptr;
	v.size = 0;

	return *this; //*this is a self-reference
	// TODO: insert return statement here
}


/*
Allocate temporary dynamic array of size v (v1)
Copy v1 elements to temp array
Deallocate old v2 nums array
point v2 nums array to temp array
set v2 size to v1 size
return a self copy of Vector
*/
Vector & Vector::operator=(const Vector & v)
{
	int* temp = new int[v.size];

	for (size_t i = 0; i < v.size; ++i)
	{
		temp[i] = v[i];
	}

	delete nums;

	nums = temp;
	size = v.size;

	return *this; //sends a copy of itself back
}

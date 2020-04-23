//

#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<cstddef>
#include <stddef.h>

class Vector
{
public:
	Vector(size_t sz);
	Vector(const Vector& v); //copy constructor
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i)const { return nums[i]; }
	~Vector(); //destructor that frees the memeory.
private:
	size_t size; // stack variable
	int* nums; //tells the compiler to save memory block
};

#endif 

//this does not belong to the class
//it's a free function
void use_vector();

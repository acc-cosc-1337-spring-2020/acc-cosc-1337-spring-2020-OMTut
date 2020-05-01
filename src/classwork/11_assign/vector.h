//

#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<cstddef>
#include <stddef.h>

class Vector
{
public:
	Vector(size_t sz);
	Vector(const Vector& v); //copy constructor - Rule of 3
	Vector& operator=(const Vector& v); //copy assignment - Rule of 3
	Vector(Vector&& v); //move constructor - Rule of 5 - for c++11 and higher
	Vector&operator=(Vector&& v); //move assignment - reasigns pointers Rule of 5 - c++11
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i)const { return nums[i]; }
	void Reserve(size_t new_allocation);
	~Vector(); //destructor that frees the memeory. - Rule of 3  //Allocate, Reassign, Delete memory...C++98
private:
	size_t size; // stack variable
	int* nums; //tells the compiler to save memory block
};

#endif 

//this does not belong to the class
//it's a free function
void use_vector();

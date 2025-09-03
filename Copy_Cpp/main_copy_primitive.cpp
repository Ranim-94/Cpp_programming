
#include <iostream>

struct vec_2{
    float x,y; // coordinates of the vector
};


int main(){

// 1- Start with some primitive data types

int a{5}; // Declaring and initializing some variable

int b = a;

/*
    Here we are copying primitive data types
    we are just copy the value of a into b

    However, a and b have different memory addresses

*/

std::cout<<" 1 - Working with primitive data types a and b"<<std::endl<<std::endl;

std::cout << " \t a (initialized) = " << a << " at address: " << &a << std::endl;
std::cout << " \t b (using b = a) = " << b << " at address: " << &b << std::endl;
std::cout << "\t\t Note!!:  a and b have different memory addresses" << std::endl << std::endl;

// Now changing the value of a
a = 10;

std::cout << " \t a (after change) = " << a << " at address: " << &a << std::endl;
std::cout << " \t b (after change) = " << b << " at address: " << &b << std::endl;
std::cout<<" \t\t !! Note !!: b still the same after change of a even if a = b " << std::endl<< std::endl;

// 2- =================== Now with struct ===================

vec_2 v1{1.0f, 2.0f};
vec_2 v2 = v1;

/*
    Here we are copying struct data types
    we are just copy the value of v1 into v2
*/

std::cout<<" 2 - Working with struct data type vectors v1 and v2"<<std::endl;

std::cout << "\t v1: x = " << v1.x << ", y = " << 
v1.y << " at address: " << &v1 << std::endl;

std::cout << "\t v2 (v2 = v1 [using copy]): x = " << 
v2.x << ", y = " << v2.y << " at address: " << &v2 << std::endl<< std::endl;

// 3- =================== Now with pointers and dynamic memory ===================

// allocating and initializing a vector on the heap
vec_2* v3 = new vec_2{.x = 2.0f, .y = 3.0f}; 

vec_2* v4 = v3; // copying the pointer (address) of v3 into v4

/*
    Now with pointers, the 2 variable v4 and v3 share the same memory addresses
    since v4 and v3 point to the same location on the heap

    Which mean unlike v1 and v2, if we change the value of v3 or v4, both will reflect the change

*/


std::cout<<" 3 - Working with struct data type vectors v3 and v4"<<std::endl;
    std::cout<<" \t !!! But dynamically allocated <-> with pointers"<<std::endl;

std::cout << "\t v3 (initialized): x = " << v3->x << ", y = " << 
v3->y << " at address: " << v3 << std::endl;

std::cout << "\t v4 (v4 = v3 [using copy]): x = " << 
v4->x << ", y = " << v4->y << " at address: " << v4 << std::endl<<std::endl;

// changing the value of v3
v3->x = 5.0f;
v3->y = 6.0f;

std::cout << "\t After changing v3 (but not touching v4):" << std::endl;
std::cout << "\t v3: x = " << v3->x << ", y = " << v3->y << " at address: " << v3 << std::endl;
std::cout << "\t v4: x = " << v4->x << ", y = " << v4->y << " at address: " << v4 << std::endl;

// Clean up dynamically allocated memory
delete v3;

} /* End main() */
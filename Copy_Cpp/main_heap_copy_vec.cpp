


#include <iostream>
#include "src/heap_vec.hpp"

int main(){

    float x {5}, y {10};

    heap_vec2 v1{x,y}; // normal constructor

    auto [x1,y1] = v1.get_coordinates();

    std::cout << "\t Coordinates of v1: (" << x1 << "," << y1 << ")" 
    << std::endl;

    // Creating object vector v2 and initialize it to v1
    heap_vec2 v2{v1}; // copy constructor

    auto [x2,y2] = v2.get_coordinates();

    std::cout << "\t Coordinates of v2 (initialized by v1): (" 
    << x2 << "," << y2 << ")"<< std::endl;

    // Changing v2 now: setting a new x coordinate
    v2.set_x(15);

    // printing value again
    auto [x2_new,y2_new] = v2.get_coordinates();

    std::cout << "\t Coordinates of v2 (after modification of x coordinate): (" 
    << x2_new << "," << y2_new << ")" << std::endl;

    /*
        !! NOTE !! since we have defined a copy constructor in a proper way,
        v1 won't change when we modify v2, and vice versa.
    
    */

    // =========== Custome Copy Assignment Operator =============

    std::cout << "\t =========== Custome Copy Assignment Operator =============" 
    << std::endl<< std::endl;

    heap_vec2 v3; // default constructor
    // v3 is (-1,-1)

    // create some 4th vector
    heap_vec2 v4{20,30}; // normal constructor

    std::cout << "\t Coordinates of v3 (before assignment): (" <<
        "x = " << std::get<0>(v3.get_coordinates()) << "," <<
        "y = " << std::get<1>(v3.get_coordinates()) << ")" << std::endl;

    v3 = v4; // custom copy assignment operator
    // we are assigning v4 to v3 -> result should be x = 21 and y = 31

    std::cout << "\t Coordinates of v3 (after assignment to v4): (" <<
        "x = " << std::get<0>(v3.get_coordinates()) << "," <<
        "y = " << std::get<1>(v3.get_coordinates()) << ")" << std::endl;


    return 0;


} /* End main() */


/*
    Notes:

    In this example, we demonstrated the use of a copy constructor for a class that manages its own dynamic memory. The copy constructor ensures that when we create a new object as a copy of an existing one, the new object gets its own separate copy of the dynamically allocated memory. This prevents issues like double deletion and ensures that each object manages 
    its own resources properly.

    The members of the class are pointers, and the constructor
    initializes them dynamically using new keyword.

    When creating object v2 (line 18) and initilize them by v1,
    we need to have copy constructor defined in the class, which
    allocate different memory space, then we can assign the values we need

    By this way when the program ends and destructor called, memory will
    be clean correctly, and no deletion issues will arise by calling delete operator twice on the same memory address.
    twice on the same memory location.

*/
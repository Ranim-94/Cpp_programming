

#include"src/vectors.hpp"

#include <iostream>

int main(){

    // Setting some initial coordinates
    float x{5}, y{10};

    Vector2 v1{x,y}; // normal constructor

    Vector2 v2; // default constructor
    /* Notice that no {} are used */

    
    std::cout << "Coordinates of v1: x = " << v1.get_x() << "| y = " 
    << v1.get_y() << std::endl;

    std::cout << "Coordinates of v2 (default constructor): x = " << v2.get_x() << "| y = " 
    << v2.get_y() << std::endl;

    // Some heap allocated object v3

    Vector2* v3 = new Vector2{15,20}; // normal constructor

    std::cout << "Coordinates of v3 (heap allocated): x = " << v3->get_x() << "| y = " 
    << v3->get_y() << std::endl;

    delete v3; // Don't forget to free the allocated memory
    // because destructor is not called automatically for heap allocated objects

    return 0;

} /* End main() */


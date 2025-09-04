#include "vectors.hpp"


// Default Constructor: no arguments are passed
Vector2::Vector2():
m_x{-1},m_y{-1}{

    
}

Vector2::Vector2(float& x, float& y)
:m_x{x},m_y{y}{

}

// Copy Constructor
Vector2::Vector2(const Vector2& vec2)
:m_x{2*vec2.m_x}, m_y{2*vec2.m_y}{

}

/*
    In this version of the copy constructor, 
    the member variables are initialized 
    to double the values of the original vector.

    By this way we can illustrate its usage in the code

*/


void Vector2::set_x(float& x){

this->m_x = x;

}

void Vector2::set_y(float& y){

this->m_y = y;

}


float Vector2::get_x(void){

    return this->m_x;
}

float Vector2::get_y(void){

    return this->m_y;
}

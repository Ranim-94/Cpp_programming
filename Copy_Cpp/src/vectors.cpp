#include "vectors.hpp"


// Default Constructor: no arguments are passed
Vector3::Vector3(){

    this->m_x = -1;
    this->m_y = -1;
    this->m_z = -1;
}

Vector3::Vector3(float& x, float& y, float& z)
:m_x{x},m_y{y},m_z{z}{

}

// Copy Constructor
Vector3::Vector3(const Vector3& vec3)
:m_x{2*vec3.m_x}, m_y{2*vec3.m_y}, m_z{2*vec3.m_z}{

}

/*
    In this version of the copy constructor, 
    the member variables are initialized 
    to double the values of the original vector.

    By this way we can illustrate its usage in the code

*/


void Vector3::set_x(float& x){

this->m_x = x;

}

void Vector3::set_y(float& y){

this->m_y = y;

}

void Vector3::set_z(float& z){

this->m_z = z;

}

float Vector3::get_x(void){

    return this->m_x;

}
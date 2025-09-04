#include "vectors.hpp"

#include <iostream>

Vector2::Vector2():
m_x{-1},m_y{-1}{

    std::cout << "\t Default constructor called" << std::endl;
}

Vector2::Vector2(float x, float y):
m_x{x},m_y{y}{

    std::cout << "\t Parameterized constructor called" << std::endl;
}

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
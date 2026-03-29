#include "vectors.hpp"

#include <iostream>

Vector2::Vector2():
m_x{-1},
m_y{-1},
m_vec_name{"dummy_vec"},
m_vec_id{"dummy_vec_-1_-1"}
{

    std::cout << "\t Default constructor called" << std::endl;
}

// Paramertrized constructor, intializing attributes using member intializer list
Vector2::Vector2(float x, float y,std::string vec_name):
m_x{x},
m_y{y},
m_vec_name{vec_name},
m_vec_id(vec_name.append("_"+std::to_string(x)+"_"+std::to_string(y)))
{

    std::cout << "\t Parameterized constructor called" << std::endl;
}

/*
    ID of vec is formed by its name, then concatenating 
    x and y spearated by "_"
    Example: vec name is v1
    vec id = v1_x_y
*/

/*
  - In this method, we used what we call member intializer
    to initilialize the attributs of the class Student.
    after the :, the member variable m_x will be initialized
    by the value of the x

    - note that in the member initializer list [in m_id attribute], 
    we can: 
        - call functions as in m_vec_id: we use append() from string library
            - we can also call a constructor of another object, since the constructor is also
            a function

        - use also other attributes
            - m_vec_id is intialized using x, y and vec_name
            - it is not initialized by the constructor argument
            in direct way, like I don't have std::string some_vec_id as for std::string vec_name
        
            


*/


// Some methods: setting, getting and logging

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

void Vector2::log_vec(void){

std::cout<<" -> Logging info for vec "<<this->m_vec_name<<std::endl;

    std::cout<<"\t x = "<<this->m_x
    <<"| y = "<<this->m_y<<"| id = "<<this->m_vec_id
    <<std::endl<<std::endl;

}



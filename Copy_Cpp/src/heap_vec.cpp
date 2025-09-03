

#include"heap_vec.hpp"
#include<iostream>


// Default Constructor
heap_vec2::heap_vec2():
m_x(new float{0}),m_y(new float{0}){
    std::cout << "\t -> Normal constructor called" << std::endl;

}


// Normal Constructor
heap_vec2::heap_vec2(float x, float y):
m_x(new float{x}), m_y(new float{y}) {

  std::cout << "\t -> Normal constructor called" << std::endl;
}

/*
    Equivalent: 

    heap_vec2::heap_vec2(float x, float y){

    std::cout << "\t -> Normal constructor called" << std::endl;

    this->m_x = new float;
    // we can also write this: m_x = new float;
    this->m_y = new float;
    *(this->m_x) = x;
    *(this->m_y) = y;
}

*/


 // Copy constructor   
 heap_vec2::heap_vec2(const heap_vec2& some_vec2):
 m_x(new float{*some_vec2.m_x}),m_y(new float{*some_vec2.m_y}){

    std::cout << "\t -> Copy constructor called" << std::endl;

}

 heap_vec2::~heap_vec2(){
    // deallocate the memory on the heap
    delete this->m_x;
    delete this->m_y;
 }


std::tuple<float, float> heap_vec2::get_coordinates() const {

    return std::make_tuple(*(this->m_x), *(this->m_y));
}

void heap_vec2::set_x(float x) {
    *(this->m_x) = x;
}





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

// Custom copy assignment operator
heap_vec2& heap_vec2::operator=(const heap_vec2& rhs_vec2){
  
      std::cout << "\t -> Custom copy assignment operator called" << std::endl;

        // self-assignment check
        if(&rhs_vec2 == this){
            return *this;

        /*
            This check mean for example
            we don't want to do something like this:
            a = a; or vec1 = vec1;
            So we return the current object itself
        */    
        } /* End if(&rhs_vec2 == this)*/

        // deallocate the memory on the heap
        delete this->m_x;
        delete this->m_y;

        // allocate new memory on the heap and copy the values
        this->m_x = new float{*rhs_vec2.m_x};
        this->m_y = new float{*rhs_vec2.m_y};

        // for the sake of difference and make the copy assignment operator
        // a little different , I will add 1 to the copied values
        *(this->m_x) += 1;
        *(this->m_y) += 1;

        return *this;

} /* End Custom copy assignment operator */

// Destructor
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



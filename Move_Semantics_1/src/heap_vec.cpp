

#include"heap_vec.hpp"
#include<iostream>


// Default Constructor
heap_vec2::heap_vec2():
m_x(new float{0}),m_y(new float{0}){
    std::cout << "\t -> Default constructor called" << std::endl;

}


// Normal Constructor
heap_vec2::heap_vec2(const float x, const float y):
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

heap_vec2::heap_vec2(heap_vec2&& some_vec2) noexcept{

    std::cout << "\t -> Move constructor called" << std::endl;

    // Steal the resources: in this case, I am rewiring the pointers
    this->m_x = some_vec2.m_x;
    this->m_y = some_vec2.m_y;

    // Leave the moved-from object in a valid state
    // in this case, we assign the pointer to nullptr
    some_vec2.m_x = nullptr;
    some_vec2.m_y = nullptr;


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
    
    std::cout << "\t -> Destructor called" << std::endl;

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


float heap_vec2::get_x() const{

    return *(this->m_x);
}

float heap_vec2::get_y() const{
    
    return *(this->m_y);

}


Vec_Entity::Vec_Entity(const float& x,const float& y):
m_vec2{x,y}{

    std::cout<<"\t -> Vec_Entity normal constructor called"<<std::endl;

}

// Move constructor
Vec_Entity::Vec_Entity(Vec_Entity&& other):
m_vec2{std::move(other.m_vec2)}{

    std::cout<<"\t -> Vec_Entity move constructor called"<<std::endl;

}

 void Vec_Entity::printVec_info(const std::string& vec_name){

    std::cout<<"\t "<<vec_name<<" info: "<<std::endl;
    std::cout<<"\t \t x= "<<this->m_vec2.get_x()<<"| y = "
    <<this->m_vec2.get_y()
    
    <<std::endl<<std::endl;

}


#include"heap_vec.hpp"

#include<iostream>


/*

    Recall that m_x and m_y are pointers

*/

// Default Constructor <-> no input arguments
heap_vec2::heap_vec2():
m_vec_name{"v_0"},
m_x(new float{0}),
m_y(new float{0}){
    
    std::cout << "\t -> Default constructor called" << std::endl<< std::endl;

} // End heap_vec2()


// Normal Constructor <-> takes some input arguments
heap_vec2::heap_vec2(std::string vec_name,float x, float y):
m_vec_name{vec_name},
m_x{new float{x}}, 
m_y{new float{y}} {

  std::cout << "\t -> Normal constructor called" 
  <<std::endl<<std::endl;

} /* End heap_vec2() */

/*
    Equivalent: 

    heap_vec2::heap_vec2(float x, float y){

    std::cout << "\t -> Normal constructor called" << std::endl;

    this->m_x = new float;
    // we can also write this: m_x = new float;
    this->m_y = new float;
    
    // Setting values
    *(this->m_x) = x;
    *(this->m_y) = y;
}

*/
 
// Deep Copy constructor 
 heap_vec2::heap_vec2(const heap_vec2& some_vec2):
 m_x{new float{*some_vec2.m_x + 2}},
 m_y{new float{*some_vec2.m_y + 2}}{

    std::cout << "\t -> Deep Copy constructor called (+2 added)" 
    <<std::endl<<std::endl;

   /*
        - In deep copy constructor, we allocate new memory using the 
        "new" keyword
            - by this way we don't have 2 objects which points to 
            same memory , and changing in one won't affect the other

        - we only use the values of the input object "some_vec2"

        - I will add "2" to hilight I am using deep copy constructor
   */ 

} // End heap_vec2() deep copy constructor



// Custom copy assignment operator
heap_vec2& heap_vec2::operator=(const heap_vec2& rhs_vec2){
  
      std::cout << "\t -> Custom copy assignment operator called (+1 added)" 
      <<std::endl<<std::endl;

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

        /*
            In copy assignment operator, we de-allocate our memory
            since the destructor is not called 

            It is only called with constructor, and here
            we have operator overloading with "=" <->
            no constructor is called
        
        */


        // allocate new memory on the heap and copy the values
        this->m_x = new float{*rhs_vec2.m_x};
        this->m_y = new float{*rhs_vec2.m_y};

        // for the sake of difference and make the copy assignment operator
        // a little different , I will add "1" to the copied values
        *(this->m_x) += 1;
        *(this->m_y) += 1;

        return *this;

} /* End Custom copy assignment operator */

// Destructor
 heap_vec2::~heap_vec2(){
    
    std::cout<<"\t Destructor Called"<<std::endl<<std::endl;

    // deallocate the memory on the heap
    delete this->m_x;
    delete this->m_y;


 } // End ~heap_vec2()



void heap_vec2::set_name(std::string vec_name){

    this->m_vec_name = vec_name;
}

void heap_vec2::set_x(float x) {
    *(this->m_x) = x;
}

void heap_vec2::set_y(float y) {
    *(this->m_x) = y;
}


float heap_vec2::get_x(void){

    return *(this->m_x);

}

float heap_vec2::get_y(void){

    return *(this->m_y); 

}

void heap_vec2::log_vec_info(void){
   
   // Logging info for a vec such as name, x,y....
   
 std::cout<<"\t -> Logging info for "<<this->m_vec_name<<":"<<std::endl;

 // Coordinate values
 std::cout<<"\t \t - Coordinate values:"<<std::endl;
 std::cout<<"\t \t \t  x = "<<*(this->m_x)<<"|"<<"y = "
 <<*(this->m_y)<<std::endl;

 // Member addresses
 std::cout<<"\t \t - Addresses:"<<std::endl;
 std::cout<<"\t \t \t  x = "<<(this->m_x)<<"|"<<"y = "
 <<(this->m_y)<<std::endl;


std::cout<<"-----------------------------------------------------"<<
std::endl<<std::endl;

}// End log_info()



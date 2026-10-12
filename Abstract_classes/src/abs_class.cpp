
#include "abs_class.hpp"

#include <iostream>

/* Constructor for the abstract base class */
Student::Student(std::string name):
m_name(name){};


/* Constructor for the derived class*/
Med_Student::Med_Student(std::string name):
Student(name){};


void Med_Student::log(void) {

 std::cout<<"Hello I am med Student \n";

 std::cout<<"My name is "<<this->m_name<<std::endl;

} /* End log() */
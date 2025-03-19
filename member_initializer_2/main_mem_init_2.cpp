
#include "Student.hpp"

#include <iostream>



int main(void){

std::cout<<"Working with member intializer - part 2 "<<std::endl;

    /* Workign with member initializer with object as attribute */

    Student stud_1("John",2014,"Medical");

    std::cout<<"stud_1 info : \n";

    stud_1.log_info();



} /* End main() */

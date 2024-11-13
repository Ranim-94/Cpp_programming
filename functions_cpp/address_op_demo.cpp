
#include <iostream>
#include "address_op_demo.hpp"



void run_address_operator_demo(void){

// declaring and initializing some variables
int nb1 = 5;
float nb2 = 3.2;
char b = 'c';

std::cout<<"-> address of nb1 = "<< &(nb1) <<std::endl ;

std::cout<<"-> address of nb2 = "<< &(nb2) <<std::endl ;

std::cout<<"-> address of b = "<< (void*)&(b) <<std::endl ;

/*
    note: if we type
    std::cout<<"-> address of b = "<< &(b) <<std::endl ;
    such as the others, cpp will treated as string, so we need to caste
    it via (void*)

*/


} // End run_add_op_demo()



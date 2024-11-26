

/* 

    Description: this file contains usage of & operator
    1- as getting address of variables
    2- setting aliases

    3- usage of typeid() to deduce type of variable
        - #include <typeinfo>

*/


#include "ampersand_operator.hpp"

#include <iostream>
#include <typeinfo>

void run_ampersand_operator_demo(void){


std::cout<<"1st usage of & operator: getting addresses"<<std::endl<<std::endl;

// declaring and initializing some variables
int nb1 = 5;
float nb2 = 3.2;
char b = 'c';


// 1st usage of &: getting the addresse of some variabel
// this variable can be of primitive data type, or even a function

std::cout<<"\t -> address of nb1 = "<< &(nb1) <<std::endl ;

std::cout<<"\t -> address of nb2 = "<< &(nb2) <<std::endl ;

// for the char type, we have a special case, see below
// why we need to cast to ptr
std::cout<<"\t -> address of b = "<< (void*)&(b) <<std::endl ;

// blank line between sections
std::cout<<std::endl;

/*
    note: if we type
    std::cout<<"-> address of b = "<< &(b) <<std::endl ;
    such as the others, cpp will treated as string, so we need to caste
    it via (void*)

*/

// 2nd usage of & operator: as alias

std::cout<<"2nd usage of & operator: setting aliases"<<std::endl<<std::endl;

float some_var = 2; // declare some variabel

float& alias_some_var = some_var;
// here we declare an alias to some_var of type float


/* 
    - after this assignement we have: 
        - alias_some_var and some_var have the same memory address

    - aliases need to be initialized <-> they are safer
*/



std::cout<<"\t ->some_var value = "<<some_var<<std::endl;

std::cout<<"\t ->alias_some_var value = "<<alias_some_var<<std::endl;

std::cout<<"\t ->alias_some_var type = "<<typeid(alias_some_var).name()
<<std::endl;
// the type of the alias is the same the type of the variable assigned to
// in this case float


} // End run_ampersand_operator_demo()



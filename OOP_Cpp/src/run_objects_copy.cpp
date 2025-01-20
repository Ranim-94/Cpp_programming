
#include "vectors.hpp"

#include<iostream>

/*

    Points in these demo:
    - copy assignment operator (for objects already created)
    - copy constructor -> create new objects


TODO: to see later how to create
    - custome copy constructor
    - csutome copy assignment operator

    To review videos of Mike shah about these topics
    but also to see other youtube videos and plyalist
    because Mike shah did directly use example with 
    pointers

*/


void run_objects_copy(void){

// create an instance of some vector
Vector3 my_vec_1(1,1,1);

Vector3 my_vec_2; // this with a default constructor
// Notice that since we are creating this instance
// with a defautl constructor, no need to ()

std::cout<<"\n \t 1-Copy Assignment Operator \n \n";

std::cout<<"x coordinate for my_vec_2 (default constructor) before copy = "
<<my_vec_2.get_x()<<std::endl;

// apply an assignemnt
my_vec_2 = my_vec_1;
// In fact, this is known as copy assignment operator
// It copy the content of my_vec_1 to my_vec_2
// But important: the copy assignment operator
// doesn't create new object 
// In other words, copy assignment operator
// is for objects already constructed

std::cout<<"x coordinate for my_vec_2 (default constructor) after copy = "
<<my_vec_2.get_x()<<std::endl;

// ============== Copy constructor ==============

/*
    Copy constructor indeed (unlike copy assignment operator)
    create new object

*/

std::cout<<"\n \t 2- Copy constrcutor section \n\n";

Vector3 my_3rd_vec = my_vec_1;

std::cout<<"x coordinate for my_3rd_vec using a copy constructor = "
<<my_3rd_vec.get_x()<<std::endl;

// let's change some element of my_vec_1

std::cout<<"-> Changing the x value of my_vec_1"<<std::endl;

float new_x = 5;
my_vec_1.set_x(new_x);

std::cout<<"\t - new x coordinate for my_vec_1  = "
<<my_vec_1.get_x()<<std::endl;

std::cout<<"\t - x coordinate for my_3rd_vec  = "
<<my_3rd_vec.get_x()<<std::endl;


} /* End run_objects_copy() */




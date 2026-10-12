
#include"function_demo.hpp"
// #include<iostream>

float add_nb(float nb1, float nb2){

/*
    - Here we have the defintion, or implementation of the function
    - nb1 and nb2 are called parameters
        (in main.c or whatever .c the function is called: they are called arguments)
*/

float result;

result = nb1 + nb2 ;

return result;

} // End add_two_nb

int add_nb(int nb1, int nb2){

/*
    - In Cpp, we could name 2 different functions with same name
    - the compiler is able to distinguish between them in the call
    by using for example parameters type, nb of parameters,...

*/

int result;

result = nb1 + nb2 ;

return result;


} // End add_two_nb


void vec_add_one(std::vector<int>& vec){

    for (int i = 0 ; i< vec.size(); i++){
        vec[i] += 1 ;

    } /* End loop*/


} /* End add_1 */
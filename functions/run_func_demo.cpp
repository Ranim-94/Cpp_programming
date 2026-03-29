
#include"run_func_demo.hpp"
#include "function_demo.hpp" // include functions used 
#include <iostream>
#include <algorithm>

void run_function_demo(void){


float a = 3.0, b = 2.0;

float result; // to store the value

// call the function
result = add_nb(a,b);

result = a+b ;

std::cout << "-> using add function (float type) for input = "<< a << "| b = " << b
<< " | output = " << result << std::endl;
    
int c = 2, d = 5;

// call the functions (int argument)
int res_2 = add_nb(c,d);

std::cout << "-> using add function (int type) for input = "<< c << "| b = " << c
<< " | output = " << res_2 << std::endl;

/* Trying with vectors */

/* declare some vectors*/
std::vector<int> vec(100);

/* intialize it to one */
int init_vec_value = 1 ;

std::fill(std::begin(vec),std::end(vec),init_vec_value) ;

std::cout<<"Vec[0] inital value = "<<vec[0]<<std::endl;

/* calling the function: pass the vec by reference */
vec_add_one(vec);

std::cout<<"Vec[0] after function call = "<<vec[0]<<std::endl;


} // End run_function_demo()
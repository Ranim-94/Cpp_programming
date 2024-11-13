
#include"run_func_demo.hpp"
#include "function_demo.hpp" // include functions used 
#include <iostream>

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


} // End 
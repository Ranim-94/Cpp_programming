
#include "l_r_value.hpp"

#include <iostream>
#include <string>

/*
    Some main idea in this lesson:

    1- l_value: something with a memory location
        we can use the &() operator

    2- r_value: on the right side of the assignment
        - does not point to anywhere

    3- move semantics and the ownership
        these are the concepts we will explore

*/


void run_l_r_value(void){

   /* l_value and l_value_ref */

    int a = 10; /* a is a l_value */

    int& a_ref = a; /* a_ref is l_value_reference */

    std::cout<<"l value reference = "<<a_ref<<std::endl;

    /*
        we can also do the following:
        const int& ref = 10;

        usually, int& ref = 10; will give us an error

        but const int& ref = 10; under the hood, we have like:

        int temp = 10;
        int& ref = temp; 
        the compiler with const will do some movement 
    
    */

    /* ========== Example of rvalue ========== */

    std::string s1 = "Hi ";

    std::string s2 = "and Bye";

    std::string&& s3 = s1+s2;
    /*
        here we have r_value ref
        it help us to prevent copy , and use the existing variables
        s1 and s2

        - the && will refere to the right value
        in this case s1 and s2
        - point or refer to the value created by s1+s2
        (a concatenation operation), without copying 
        to the address of s3

        TODO: I need to see the difference later between l_value ref
        and right value_ref, because till now the difference is not 
        clear for me yet

    */

   std::cout<<"r_value ref for strings: "<<s3<<std::endl;





} /* End run_l_r_value() */







#include<iostream>
#include"src/helper_functions.hpp"

int main(){

int a = 5;
/*
    1. An L value can be thought of a variable that 
    is on the left side of an assignment.
        - It has a memory location (address).
        - it has a storage that persists beyond the expression that uses it.

    2. Now the R value is a value that is on the right side
    of an assignment. 
        - The '5' is simply a constant, which has
        no memory location (address).
        - It is a temporary value that does not persist beyond the expression that uses it.

    3. Example: we can't say '5 = a', because 5 is not 
    a variable that has some memory location we can store in it.

*/

// -------------- Case 1: Normal L value -----------------

// L and R values with functions

int var2 = double_data(a); // creating an L value using an L value
/*

    we can also call int var2 = double_data(5)
    so using directly the R value
    <-> that is creating an L value using an R value
*/

/*
    SO recap: L value can be created using either
        1- an L value
        2- an R value
*/



std::cout << "\t var2 = " << var2 << std::endl;
std::cout << "\t \t var2 after calling double_data(a): " << std::endl;


// -------------- Case 2: L value reference -----------------


// Acceptable
int var3 = double_data_by_reference(a); // creating an L value reference using an L value
// Not Acceptable <-> creating an L value reference using an R value (the 5 in our case)
// int var4 = double_data_by_reference(5);

// because usually in C++ we can't have a statement like below
// int& ref = 5; // not acceptable

std::cout << "\t var3 = " << var3 << std::endl;
std::cout<<"\t \t L value reference using L value" << std::endl<< std::endl;

// The only way to create an L value reference using an R value 
// is to use const with the L value reference as shown below
 int var4 = double_data_by_reference_const(5);

std::cout << "\t var4 = " << var4 << std::endl;
std::cout<<"\t \t L value reference using R value, but with const" << std::endl<< std::endl;

/*
    Recap: L value reference can be created using either
        1- an L value
        2- an R value but only if the L value reference is const

*/

// -------------- Case 3: R value reference: int&& -----------------

// We can call functions also using R value or some temporary objects using R value reference
int var5 = double_data_by_reference_rvalue(5); // creating an R value reference
// this function accepts R value refernces that is int&& = 5;

std::cout << "\t var5 = " << var5 << std::endl;
std::cout<<"\t \t R value references (int &&) using R value" << std::endl<< std::endl;

return 0;

} /* End main() */

/*
    General Notes:

    usage of temporary objects or R values
    - R values are usually temporary values that do not persist beyond the expression that uses them.
    - Theire are often used for optmization purposes, to avoid unnecessary copying of data.
        - we dont' have to worry about making keep them alive or intact
        - we can simply steal their resources



*/



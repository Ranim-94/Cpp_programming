

#include <iostream>
#include <vector>  // for vector type
#include <algorithm> // for functions such that fill()

#include "src/helper_functions.hpp"

/*
    A simple demo about vectors containers
*/

int main(void){

/* declare some vectors*/
std::vector<int> vec(100);

/* intialize it to one */
int init_vec_value = 1 ;

std::fill(std::begin(vec),std::end(vec),init_vec_value) ;

std::cout<<"Vec[0] inital value = "<<vec.front()<<std::endl;
// vec.front() = vec[0]    

/* calling the function: pass the vec by reference */
increment_vec(vec);

std::cout<<"Vec[0] after function call = "<<vec.front()<<std::endl;

/* create some other vectors using {}*/

std::vector<int> vec_2{12,13,14};

/* using some functions in the vector<> container */


std::cout<<"Vec_2[end]  = "<<vec_2.back()<<std::endl;

/* pushing some element to the end */
vec_2.push_back(15);

std::cout<<"Vec_2[end] after pushing some element  = "
<<vec_2.back()<<std::endl;

/* adding some element at the begining */
vec_2.insert(vec_2.begin(),11);

std::cout<<"Vec_2[0] after inserting some element  = "
<<vec_2.front()<<std::endl;

/* there is alsoe vec_2.erase(some position),...*/


return 0;

}/* End main ()*/
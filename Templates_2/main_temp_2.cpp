


#include "src/sum.hpp"
#include "src/function_demo.hpp"

#include<iostream>
#include <algorithm>

int main(){


float nb_1 = 2.3f;

int nb_2 = 4;

auto nb3 = sum<float,int>(nb_1,nb_2);

std::cout<<"Adding up "<<nb_1<<" + "<<nb_2<<" = "<<nb3<<std::endl;

/* declare some vectors*/
std::vector<int> vec(100);

/* intialize it to one */
int init_vec_value = 1 ;

std::fill(std::begin(vec),std::end(vec),init_vec_value) ;

std::cout<<"Vec[0] inital value = "<<vec[0]<<std::endl;

/* calling the function: pass the vec by reference */
vec_add_one(vec);

std::cout<<"Vec[0] after function call = "<<vec[0]<<std::endl;




} /* End main()*/
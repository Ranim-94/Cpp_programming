

#include <iostream>

#include"src/heap_vec.hpp"

#define LINE std::cout<<"-----------------------------------------"<<std::endl; 


int main(){


Vec_Entity v1{5,10}; // normal constructor

v1.printVec_info("v1");

Vec_Entity v2 = std::move(v1);

v2.printVec_info("v2");



return 0;


} /* End main() */
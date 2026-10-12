
#include "ptr_basics.hpp"

#include<iostream>

/* Fundamental idea about ptr

 - they are variables which store addresses of some data
 - they let us share data between many sources
    - prevent copy and paste

 - memory management: control the life time of an object

*/

void run_ptr_basics(void){

   /* declare and initialize some variable*/
   int x = 7; 

   /* attache the ptr_x to variable x, using & operator */
   int* ptr_x = &x ; 

   std::cout<<" x value = "<<x<<std::endl;

   std::cout<<" x address = "<<&x<<std::endl;

   std::cout<<" x_ptr content = "<<ptr_x<<std::endl;

   std::cout<<" x value using ptr dereferencing = "<<*ptr_x<<std::endl;

} /* End run_ptr_basics() */
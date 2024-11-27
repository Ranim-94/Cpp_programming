
#include "dynamic_array.hpp"

#include <iostream>
#include <cstdlib> 

void run_dynamic_array(void){

int nb_elements = 10;

/* allocate for 10 elements at the heap*/
float* some_arr = new float[nb_elements];

generate_randome_array(some_arr,nb_elements);

print_array(some_arr,nb_elements);

/* Don't forget to dallocate*/
delete[] some_arr;


} /* End run_dynamic_array()  */

void generate_randome_array(float* ptr_arr, int& nb_elements){

/* to generate randome numbers each time we run the code*/
srand(time(NULL));

for (int i=0 ; i < nb_elements; i++){

/* floating point between 0 and 1*/
ptr_arr[i] = (float)rand()/(float)(RAND_MAX);

ptr_arr[i] *= nb_elements; /* scale up */

} /* End for*/


} /* End generate_randome_array()*/

void print_array(float* ptr_arr,int& nb_elements){

for (int i=0 ; i < nb_elements; i++){

std::cout<<"# "<<i+1<<" = "<<ptr_arr[i]<<std::endl;

} /* End for */


} /*End print_array()*/
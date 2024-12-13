#include "raw_array.hpp"
#include "ptr_helper_functions.hpp"

#include <iostream>
#include <numeric>
#include <iterator>


#define ARRAY_SIZE 100

void run_raw_array(void){

/* creating some array of Id for example*/

/* In cpp, we illustrate 1st the raw array*/

/* Creating the array*/
int arr_id[ARRAY_SIZE];

/* Instead of using for loop, we will  use algorithm for std in cpp*/

int start_value = 0;

/* filling array value from a starting value*/
std::iota(std::begin(arr_id),std::end(arr_id),start_value);

/*
    std::iota -> apply algorithm on data structures like arrays

*/

 
/* log out array*/
print_1D_int_arr(arr_id,ARRAY_SIZE);


} /* End run_raw_array() */
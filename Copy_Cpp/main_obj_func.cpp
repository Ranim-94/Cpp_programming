


#include"src/vectors.hpp"
#include"src/helper_function.hpp"

#include<iostream>

#define LINE std::cout<<"-----------------------------------------"<<std::endl; 

#define PRINT_NB 5

int main(){

    Vector2 vec_a{-2,3}; // Default constructor is called

    std::cout<<"Before for loop"<<std::endl;

    printVec_info(vec_a,"vec_a");

    LINE

    for (int i = 0; i < PRINT_NB; i++){
        
        std::cout<<"Iteration number: "<<i+1<<", ";
        printVec_info(vec_a,"vec_a");
        

    } /* End for loop */

    LINE
    LINE

    std::cout<<"\t Passing object by reference"<<std::endl<<std::endl;


      for (int i = 0; i < PRINT_NB; i++){
        
        std::cout<<"Iteration number: "<<i+1<<", ";
        printVec_info_by_ref(vec_a,"vec_a");
        

    } /* End for loop */
    
    











} /* End main() */





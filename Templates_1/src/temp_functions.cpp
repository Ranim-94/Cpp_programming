
#include "temp_functions.hpp"

template<typename T>
extern void printVec(std::vector<T>& vec_in){

    for (T elem:vec_in){

    std::cout<<"\t-> "<<elem<<std::endl;

}/* End for loop*/


} /* End printVec() */


template void printVec(std::vector<float>& vec_in);

template void printVec(std::vector<int>& vec_in);

template void printVec(std::vector<std::string>& vec_in);
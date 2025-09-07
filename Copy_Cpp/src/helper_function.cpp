

#include "helper_function.hpp"

#include <iostream>


void printVec_info(Vector2 vec2, const std::string& vec_name){

std::cout<<"\t "<<vec_name<<" info: "<<std::endl;
std::cout<<"\t \t x= "<<vec2.get_x()<<"| y = "<<vec2.get_y()
<<std::endl<<std::endl;


} /*End printVec_info() */


void printVec_info_by_ref(const Vector2& vec2,
    const std::string& vec_name){

    std::cout<<"\t "<<vec_name<<" info: "<<std::endl;
    std::cout<<"\t \t x= "<<vec2.get_x()<<"| y = "<<vec2.get_y()
    <<std::endl<<std::endl;

} /* End printVec_info_by_ref() */
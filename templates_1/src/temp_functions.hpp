
#pragma once

#include <iostream>
#include <vector>


template<typename T>
extern void printVec(std::vector<T>& vec_in);


/*
    

    1) template concept:

    template: ways for generic programming
    are also bleuprint for functions

    Once we call the printVec() with the correspondent
    type, such as float for example -> 

    void printVec(std::vector<float>& vec_in)

    <-> T is replaced by float
    
    the compiler will generate
    the correct function with the suitable type

    2) Now here is the important thing about template
    - these template function are not the actual function,
    there are only bleuprint or more formally called "pattern"

    - the compiler needs to see the type and the template definition
    (and not only the declaration) as in standard cpp typed functions

    - that' why we can't separate template code into .hpp and .cpp

    nice resources about that:
    https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

        -this is a nice resource about template in generale
        - scrolle down to the question of 
            "Why can’t I separate the definition of my templates class from its declaration and put it inside a .cpp file?"

    
    now in order to separate the code into .hpp and .cpp for 
    tempalte case, I use the suggestion from the link above
    using export keyword, and also provding the declaration
    in the .cpp file for the called type 


*/


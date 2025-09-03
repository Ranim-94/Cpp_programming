

#include <iostream>
#include <vector>

#include "src/temp_functions.hpp"

int main(void){

std::vector<float> vec_1 = {1.2,1.3,1.4};

std::vector<int> vec_2 = {5,9,10};

std::cout<<"printing vec_1 content"<<std::endl;

/*calling the template functions*/
printVec<float>(vec_1);


std::cout<<"printing vec_2 content"<<std::endl;

printVec<int>(vec_2);

/* when calling a template function, we need to specify the 
    type also such as float, int or std::string also

In other words, it is not like normal function where
we type printVec(vec_2)

*/

// Defining some string vectors
std::vector<std::string> vec_str{"Adam","Steve","Paul"};

std::cout<<"printing vec_str content"<<std::endl;

printVec<std::string>(vec_str);




return 0;

} /* End main()*/
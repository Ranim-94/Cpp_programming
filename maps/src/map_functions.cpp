#include "map_functions.hpp"


void print_map(std::map<std::string, int>& some_map){


for (auto itr = some_map.begin(); itr != some_map.end(); itr++ ){

    std::cout<<"\t -> "<<itr->first<<" id = "<<itr->second<<std::endl;


} /* End for loop*/


}/* End print map*/
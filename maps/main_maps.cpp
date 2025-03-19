
#include <iostream>
#include <map>

#include "src/map_functions.hpp"

int main(){


std::map<std::string,int> Employees_ID {{"Steve",123},
                                        {"John",124}};

/*
    Syntax of containers:

    std::some_container<data_type> name {};


- for the map, we have 2 data types: the key and the value
- when initialize them using {}, we separate each {key,val} by a ","
*/                                        

/* accessing some element of the map using the key*/        
std::cout<<" Seteve has an id = "<<Employees_ID["Steve"]<<std::endl;

/* we can update certain element of the map*/

Employees_ID["Steve"]  = 125;

std::cout<<" Seteve id after update = "<<Employees_ID["Steve"]<<std::endl;

/* insert some element to the map*/
Employees_ID.insert({"Paul",126});

/* printing all elements*/

std::cout<<"Employes after update are :"<<std::endl;

print_map(Employees_ID);

/*
    Also their exist other functions such that
    Employees_ID.erase() -> eleminate all dict elements

*/


} /* End main() */
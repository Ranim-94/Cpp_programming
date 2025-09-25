


#include"custome_strings.hpp"

#include<iostream>
#include <cstring>

MyString::MyString(const char* string){

 std::cout<<"\t -> MyString constructor called"<<std::endl;

    this->m_size =  strlen(string);

    // Allocate on heap
    this->m_data = new char[this->m_size];

    // Copy char from source (string) -> destiation (m_data)
    memcpy(this->m_data,string,this->m_size);
    

}

MyString::~MyString(){

 std::cout<<"\t -> MyString destructor called"<<std::endl;

 delete this->m_data;

}

void MyString::print_str(){

    for(uint32_t i=0 ; i<this->m_size ; i++ ){

        std::cout<<this->m_data[i];

    } /* End for loop */

    // Insert automatically new line after printing
    std::cout<<std::endl;

    std::cout << std::flush;

} /* End print_str() */


Str_Entity::Str_Entity(const MyString& name):
m_name(name){

    std::cout<<"\t Str_Entity Constructor is called"<<std::endl;
}

void Str_Entity::print_name(){

    this->m_name.print_str();    


}/* End print_name() */
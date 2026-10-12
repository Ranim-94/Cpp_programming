

#include <iostream>

#include"src/heap_vec.hpp"

#define LINE std::cout<<"-----------------------------------------"<<std::endl; 


int main(){


Vec_Entity v1{5,10}; // normal constructor

v1.printVec_info("v1");

Vec_Entity v2 = std::move(v1);

v2.printVec_info("v2");



return 0;


} /* End main() */

	/*
	 *  Some points about move semantics:
	 *
	 *  In cpp we do a lots of copy, and copy take time
	 *
	 *  Example 1: concerning strings
	 *
	 *  	std::string s1 = "long string";
	 *
	 *  	std::string s2 = s1;
	 *
	 *  	this invokes the copy constructor, and do a copu
	 *  	literal by literal from s1 to s2
	 *
	 *
	 *  Example 2: passing arguments to functions
	 *
	 *  	func (std::string s3){
	 *
	 *  	}
	 *
	 *
	 *  	when 'func()' is invoked and being executedm
	 *  	we need to do a copy from 's3' to whatever object
	 *  	is using s3 inside the body of 'func'
	 *
	 *
	 *	Instead of passing 's3' to whatever object is using it inside
	 *	'func', we may pass the resources (transfer the ownership)
	 *
	 *	1 way we did that is using references & like implementing
	 *	the function
	 *		func(std::string& s3){
	 *
	 *		}
	 *
	 *
	 *
	 *
	 * */
















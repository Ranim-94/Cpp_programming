
#include <iostream>

#include "src/Student.hpp"

int main(){
	
	std::cout << "\t \n ========== Running OOP-Inheritance Demo !! ============= "
	<<std::endl<<std::endl;

	/* instantiating an object from base class */    
	Student stud_1{"John",2014};

	stud_1.log_info();

	/* instantiating an object from derived class */    
	Medical_Student med_1{"king",2014,"Radiology"};

	med_1.log_info();
	med_1.log_med_specialty();


	return 0;

} // End main()

/*

	Concept introduced:
	inheritance concept:
		- a method to reduce code
		- a way to establish a relationship between classes:
		   we have a base class (parent)
		   - a derived class (child)
		- the derived class inherits attributes and methods from the base class
		        - but we need to use the keyword protected 
		- the derived class can have its own attributes and methods
		        - that is some extra functionality (attributes or methods)

	
				
Some other inheritance idea based on game programming:
	- base class: weapon
	 - derived class: gun, missiles, sword, bow,....


*/



#include <iostream>

#include <string>
#include <cstdlib> // for random number generation
#include <time.h> 

#include "Character.hpp"
#include "Hero.hpp"
#include "Wizard.hpp"

#define	NB_RANGE 100

int main (){
	
	std::cout << "\t \n ========== Running OOP-Inheritance Demo !! ============= \n \n";

	// Use current time as seed for random generator 
	srand(time(0));

	// setting attributes for hero object
	float strength = (rand () % NB_RANGE),
	speed = (rand () % NB_RANGE) ,
	points = (rand () % NB_RANGE) ;
	

	// instantiate a hero character
	Hero hero_1{std::string("Conard"),strength , speed , points};

	// displaying info to consol
	hero_1.display_stats();

	/* Creating an instance for the Wizard */
	Wizard little_wizard{std::string("Arthur"),
	strength , speed , points};

	little_wizard.do_some_magic();


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



#include <iostream>

#include <string>
#include <cstdlib> // for random number generation
#include <time.h> 

#include "Character.hpp"
#include "Hero.hpp"
#include "Wizard.hpp"

#define	NB_RANGE 100

int main ()
{
	std::cout << "\t \n ========== Running OOP-Inheritance Demo !! ============= \n \n";

	// Use current time as seed for random generator 
	srand(time(0));

	// setting attributes for hero object
	float strength = (rand () % NB_RANGE),
	speed = (rand () % NB_RANGE) ,
	points = (rand () % NB_RANGE) ;
	

	// instantiate a hero character
	Hero hero_1(std::string("Conard"),strength , speed , points);

	// displaying info to consol
	hero_1.display_stats();

	/* Creating an instance for the Wizard */
	Wizard little_wizard(std::string("Arthur"),
	strength , speed , points);

	little_wizard.do_some_magic();

	// ========= Polymorphism concept =========	 

	little_wizard.defend();
	hero_1.defend();

	/* Pointers section */

	
	Character* char_hero_ptr = &hero_1;
	/* assiging a pointer of base class to point 
	 out to an address of a derived class
	*/

	Character* char_wizard_ptr = &little_wizard;

	char_hero_ptr->check_experience();

	char_wizard_ptr->check_experience();







	return 0;

} // End main
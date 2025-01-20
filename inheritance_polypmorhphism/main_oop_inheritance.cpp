
#include <iostream>

#include <string>
#include <cstdlib> // for random number generation
#include <time.h> 

#include "Character.hpp"
#include "Hero.hpp"

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

	return 0;

} // End main
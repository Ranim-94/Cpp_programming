

#include <iostream>
#include <format>
#include <string>
#include <random>

int main(){

	std::cout<<std::endl; // skip a line

	std::cout<<"\t 1) Normal string display"<<std::endl;

	// Initializing some variables
	std::string student{"Tom"};
	int age{10};

	std::cout<<std::format("\t \t -> Student name: {} | age is {}",student,age)<<std::endl;

	// std::format(): it uses place holder {} to accept string arguments


	std::cout<<std::endl; // skip a line

	// ================ 2) Field width and precision ================
	std::cout<<"\t 2) Field width and precision "<<std::endl;

	
	// generate a seed "rng" 
	std::mt19937 rng{std::random_device{}()};
	
	// generate a uniform distribution in [0,1]
	std::uniform_real_distribution<float> dist{0.0f, 1.0f};
	
	float some_nb{dist(rng)};

	std::cout<<std::format("\t \t -> Random number:{:8.4f}", some_nb)<<std::endl;

	/*
	 * 2) For Field width and precision:
	 *
	 * - the syntax of the placeholder is as follow:
	 * :8.4.f
	 *
	 * break it down:
	 *  - ":" a colon in a placeholder {} introduce a format specifier
	 *  - "8" for field width <-> in total we have 8 character for the whole number
	 *  - ".4.f":
	 *  	- (f) for floating point
	 *  	- .4: up to 4 digits precision
	 * */

	return 0;

} // End main()

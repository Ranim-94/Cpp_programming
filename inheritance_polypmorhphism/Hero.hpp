
#pragma once

/*
Class Hero is a subclass from Character class (the super class)
*/


#include<iostream>
#include<string>

// don't forget to include the parent (super)  class
#include"Character.hpp" 



class Hero:public Character{
/*
	- This mean I inherit all of attribute and methods from Character class
	- the public access modifier let us inherit what is public
			such as the methods
	- usually the attributes are private, so we use
		the keyword private so we can use them in the derived class

*/


private:
	
	// this is a specific attribute to hero class
	std::string hero_name;


public:
	
	// constructor
	Hero(std::string name,float strength,float speed,float points); 
	
	/*
		- Note that in the constructor of Hero (derived class), we need to adapt the constructor
		signature to include the attributed from the base class (Character)

		- but since we are using inheritance, we don't need to write the attibutes again
		in the private section
	
	*/


	void attack (float amount);

	~Hero();

}; /* End Hero class*/


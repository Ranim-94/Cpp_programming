#pragma once
#include<string>

class Character{

// In OOP terminology: we have what we call members
// which can be data members and functions members (the methods)


private: // this is the access modifier
	
	// list of attributes
	
	double strength,agility,speed,points, max_points,defense;
	std::string m_name;

public: // the 2nd type of access modifier

	// this is a constructor
	Character(std::string name);
	
	/*
	General points on constructors:

	- name same as the class
	- doesn't have parameters and return type
	-function: intialize parameter of the object instantiated
	that is , each time we innstantiate, the constuctor will
	allocate some memory for the members variables

	*/

	void setup_character(double strength ,double agility , 
						  double speed , double points, 
						  double max_points,double defense);

	void display_stats();

	double get_Damage();

	void take_Damage (double damage);

	~Character(); // a destructor

}; // End class character


#pragma once
class Character{

protected: 
// these attributed are only accessed by subclasses (= derived classes)
	
	// list of attributes
	float m_strength,m_speed,m_points;

public:

	// this is a constructor
	Character(float strength,float speed, float points);
	/*
	
	General points on constructors:

	- name same as the class
	- doesn't have parameters and return type
	-function: intialize parameter of the object instantiated

	*/

	
	void display_stats();

	void take_Damage (float damage);


	~Character();

}; /* End Character class */


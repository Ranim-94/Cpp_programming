

#include "Hero.hpp"

#include<string>


Hero::Hero (std::string name,float strength,
float speed,float points)
:Character(strength,speed,points){
	
	this->hero_name = name;
	
}

/* Notice in the Hero constructor
   We call also the base class constructor 
   since the base class constructor knows how to 
   initilalize the attributes

*/


void Hero::attack (float amount)
{
	this->m_strength += amount;

} // End attack_boost





Hero::~Hero (){
}

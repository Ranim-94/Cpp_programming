

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



/* this is a function common between Hero and Wizard subclasses*/
void Hero::defend(void){


   /* increasing the points when a character is defending */
   this->m_points++;

   std::cout<<this->hero_name<<"start defense"<<std::endl;

   /* Note that in polymorphism concept:
   
   - we have some common method between the 2 derived classes
   - but each is implemented in a different way

   - in this example, the difference is in using the name attribute
      - each has a different attribute name

   
   */


} /* End defend() */


Hero::~Hero (){
}

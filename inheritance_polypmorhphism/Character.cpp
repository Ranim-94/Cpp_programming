
#include "Character.hpp"

#include<iostream>


Character::Character(float strength,float speed, float points){

this->m_strength = strength;

this->m_speed = speed;

this->m_points = points;

}


void Character::display_stats(){

	// Just displaying current stats to the console

	std::cout << " \t -> Strength = " << this->m_strength << std::endl;

	std::cout << "\t -> Speed = " << this->m_speed << std::endl;	

	std::cout << "\t -> Points = " << this->m_points << std::endl;


	std::cout << "================== Finish displaying stats ===================" << std::endl<<std::endl;

} // End display_stats()


void Character::take_Damage (float damage){
	
	// Update points after taking some damage
	this->m_points = this->m_points - damage  ;;

}


void Character::check_experience(void){

 if (this->m_points > 3)
	std::cout<<" Character level is up"<<std::endl;

else
	std::cout<<" Character level is down"<<std::endl;

} /* end check_experience()  */

Character::~Character(){
}


#include "Wizard.hpp"

#include <iostream>
#include <string>

Wizard::Wizard(std::string name,float strength,float speed,float points)
:Character(strength,speed,points),m_name_wizard(name){}


void Wizard::do_some_magic(void){

    float amount = this->m_speed + this->m_strength;

    std::cout<<"Starting attack with a power of "<<amount<<std::endl;


} /* End do_some_magic() */

void Wizard::defend(void){

/* increasing the points when a character is defending */
   this->m_points++;

std::cout<<this->m_name_wizard<<" starts defense "<<std::endl;


} /* End defend() */
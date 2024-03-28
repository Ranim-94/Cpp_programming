
#include "Character.hpp"

#include<iostream>

Character::Character(std::string name){
// :: is a scope operator
// it tell us that Character is belonging to the Character class in the hpp file

	this->m_name = name;

	std::cout << "Constructor is called for " << this->m_name << std::endl;	

}// End constructor

void Character::setup_character(double strength , double agility , 
								 double speed , double points,
								 double max_points,double defense){
	this->strength = strength;

	this->agility = agility;

	this->speed = speed;

	this->points = points;

	this->max_points = max_points;

	this->defense = defense;

} // End setup_character()


void Character::display_stats(){

	// Just displaying current stats to the console

	std::cout << " \t Strength = " << this->strength << std::endl;

	std::cout << "\t Speed = " << this->speed << std::endl;

	std::cout << "\t Agility = " << this->agility << std::endl;

	std::cout << "\t Points = " << this->points << std::endl;

	std::cout << "\t Max Points = " << this->max_points<< std::endl;

	std::cout << "================== Finish displaying stats ===================" << std::endl<<std::endl;

} // End display_stats()

double Character::get_Damage(){
	return 0.0;
}


void Character::take_Damage (double damage){
	/*
	Compute points after taking some damages
	*/

	// Quantify damage after trying to defense
	double damage_after_def = this->defense - damage  ;

	std::cout << "-> Player taking damage of " << damage << "units" << std::endl;

	std::cout << "Damage after defense = " << damage_after_def << std::endl;

	// Set it minimum to 1 (we don't want values less then 1, it is a design choice)
	if (damage_after_def < 1) damage_after_def = 1 ;

	// Update points

	this->points = this->points - damage_after_def;

}


Character::~Character(){

	std::cout << "Destructor is called for " << this->m_name << std::endl;

} // End destructor ~Character()

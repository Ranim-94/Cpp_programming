

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{


private:
	double radius ;

	// static variables are shared by all instances of the class

	static int nb_of_objects ;

// *************************

	// Methods Declaration
public:
		// Construct a default circle object
		Circle();
		// Construct a circle object
		Circle(double);

		// Return the area of this circle

		// get functions are also called accessor
		double getArea(); 

		double getRadius();
		
		// -------------- Constant Member Function -----------------------------

		// What it does: tell the compiler that the function should not change the value of any data
		// fields in the object

		// defining constant member functions

		// place the key word 'const' at the end of the function header, 
		// in the .h and in the .cpp for the class file

		// only 'instance member function' can be defined as constant member function

		double getArea_c() const;
		double getRadius_c() const;

		// set functions are also called as mutator
		void setRadius(double); 

		// static functions can be accessed by any instance (object) of the class
		static int get_nb_of_objects ();


}; // We end the class with (;) 

// --------------------- Function in which the object Circle is passed ----------------------------

// by Value
void printCircle_by_Value (Circle c);

// by Reference
void print_Circle_by_Ref (Circle& c);


double sum (Circle circleArray[], int size);


void printCircleArray (Circle circleArray[], int size);






#endif



#include "Circle.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

// Initialize Static Variable

int Circle::nb_of_objects = 0; 

// no argument constructor
Circle::Circle()
{

	radius = 1;
	nb_of_objects++;

}


// Construct a circle object
Circle::Circle(double newRadius)
{
	radius = newRadius;
	nb_of_objects++;

	// Also I can use the 'this' pointer:

	// this -> raidus = newRadius ; or (*this).radius = radius ;

	// it is used to reference the data field in the object
}

// Return the area of this circle
double Circle::getArea()
{
	return radius * radius * 3.14159;
}
// Return the radius of this circle

double Circle::getRadius()
{
	 return radius;

}


// Implementation of constant member functions

double Circle::getRadius_c() const
{
	return radius;

}

double Circle::getArea_c() const
{
	return radius * radius * 3.14159;

}


// Set a new radius

void Circle::setRadius(double newRadius)
{
	radius = (newRadius >= 0) ? newRadius : 0;
}


int Circle::get_nb_of_objects()
{
	return nb_of_objects;


}

// Function in which the object circle is passed by value

void printCircle_by_Value(Circle c)
{
	cout << "The area of the circle of "
		<< c.getRadius () << " is " << c.getArea () << endl;
}


void print_Circle_by_Ref(Circle& c)
{
	cout << "The area of the circle of "
		<< c.getRadius() << " is " << c.getArea() << endl;
}


// Add circle areas for arrays of circle objects
double sum (Circle circleArray[], int size)
{
	// Initialize sum
	double sum = 0;

	// Add areas to sum
	for (int i = 0; i < size; i++)
		sum += circleArray[i].getArea ();

	return sum;
}

// Print an array of circles and their total area
void printCircleArray (Circle circleArray[], int size)
{
	cout << setw (35) << left << "Radius" << setw (8) << "Area" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw (35) << left << circleArray[i].getRadius ()
			<< setw (8) << circleArray[i].getArea () << endl;
	}

	cout << "-----------------------------------------" << endl;

	// Compute and display the result
	cout << setw (35) << left << "The total area of circles is"
		<< setw (8) << sum (circleArray, size) << endl;
}
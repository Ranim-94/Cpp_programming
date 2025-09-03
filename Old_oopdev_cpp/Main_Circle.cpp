



#include<iostream>

 #include"Circle.hpp"

//#include"Circle.cpp"

using namespace std;

int main ()
{

	Circle circle1; // Creating a default circle (so no argument)

	Circle circle2 (5.0); // Creating a 2nd circle

	cout << "The area of the circle of radius "
		<< circle1.getRadius() << " is " << circle1.getArea() << endl;

	cout << "The area of the circle of radius "
		<< circle2.getRadius() << " is " << circle2.getArea() << endl;

	// Modify circle radius
	circle2.setRadius(100); // accessing the attribute of the Circle Class

	cout << "The area of the circle of radius "
		<< circle2.getRadius() << " is " << circle2.getArea() << endl;

	// ------------- using assignmemnt operator on objects -----------------------------------

	circle1 = circle2; // copying the content of circle 2 in circle 1

	// note that the assignment operator doesn't create new objects, it just copy the content

	cout << "The radius of the circle1 is the same as circle2, which is " << circle1.getRadius() << endl;

	cout << "The area of cricle1 now is " << circle1.getArea() << endl;

	// --------------- using copy constructor -------------------------------------

	// unlike assignment operator, copy constructor create new objects

	// creating new circle object from circle 2

	Circle circle_copy_constructor(circle2);

	cout << "After creating circle_copy_constructor object from the circle2 object we have:" << endl;

	cout << "\t circle2.getRadius() returns " << circle2.getRadius() << endl;

	cout << "\t circle_copy_constructor.getRadius() returns " << circle_copy_constructor.getRadius() << endl;

	Circle c3; // creating a 3rd object

	// Passing the object by value to the function

	printCircle_by_Value(c3);

	print_Circle_by_Ref(c3);


	// --------------------- Dealing with array of objects ---------------------------------------------

	const int SIZE = 10;

	// Create a Circle object with radius 1
	Circle circleArray[SIZE];

	double radius_input[SIZE] = { 2,4,3,4,5 };

	for (int i = 0; i < SIZE; i++)
	{
		circleArray[i].setRadius(radius_input[i]);
	}

	printCircleArray (circleArray,SIZE);

	cout << endl;

	cout << "------------------------------------------------------" << endl << endl;

	cout << " Working with dynamic objects" << endl << endl ;

	// Creating dynamic object 

	Circle* circle_ptr = new Circle(20);

	cout << " The radius of the dynamic circle is " << circle_ptr->getRadius() << endl;

	cout << " The address of the circle_ptr before deleting is " << circle_ptr << endl;

	delete circle_ptr;

	cout << " The address of the circle_ptr after deleting is " << circle_ptr << endl;

	cin.get();



	return 0;



} // End main
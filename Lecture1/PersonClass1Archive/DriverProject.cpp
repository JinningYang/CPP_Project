//============================================================================
// Name        : DriverProject.cpp
// Author      : Dan Peters
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Person.h"
#include "Parent.h"

//using namespace std;
//extern void edu::neu::csye6205::functionFoo();

int main() {
	std::cout << "DriverProject main()..." << std::endl;

	edu::neu::csye6205::Person personObj = edu::neu::csye6205::Person::demo();
	std::cout << personObj.toString() << std::endl;

	/**
	 * Call function
	 */
	edu::neu::csye6205::functionFoo();

	edu::neu::csye6205::Parent parentObject;
	parentObject.speak();

	std::cout << "DriverProject main()... done!" << std::endl;

	return 0;
}

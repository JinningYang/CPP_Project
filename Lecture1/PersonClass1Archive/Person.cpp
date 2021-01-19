/*
 * Person.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: dgpeters
 */

#include <iostream>		// std::cout, std::endl, std::err
#include <sstream>		// std::sstream

#include "Person.h"		// class method specifications (declarations)
#include "Person.h"		// class method specifications (declarations)

namespace edu {
namespace neu {
namespace csye6205 {

/**
 * edu::neu::csye6200::functionFoo()
 */
void functionFoo() {
	std::cout << "I am functionFoo!" << std::endl;
}

/**
 * Static class data member
 * Declared in header (.h) file
 * BUT must be Defined in the (.cpp) source file.
 * Storage allocate with definition and
 * now we can initialize with 1
 */
int Person::version = 1;

/**
 * Default Class Constructor
 */
//Person::Person() {
//	this->age = 17;
//	this->name = "Dan";
//}
Person::Person() : age(17), name("Daniel") {
}
//Person::Person(int _age, std::string _name) : age(_age), name(_name) {
//}

Person::~Person() {
}

std::string Person::toString() {
	std::stringstream ss;

	ss << name;
	ss << ", age " << this->age;
	ss << ", version " << this->version;

	return  ss.str();
}
/**
 * demonstrate the use of this class
 *
 * edu::neu::csye6200::Person::demo()
 */
Person Person::demo() {
	/**
	 * Instantiate (create) object from Person class
	 * Allocate object on stack memory
	 * also called automatic allocation
	 */
	Person dan;		// use Default constructor
	Person jim(21, "Jim");	// use parameterized constructor
	std::cout << dan.toString() << std::endl;
	std::cout << jim.toString() << std::endl;

	functionFoo();

	return dan;	// copy object to return to caller
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

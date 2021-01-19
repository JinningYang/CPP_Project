/*
 * Person.h
 *
 *  Created on: Sep 8, 2020
 *      Author: dgpeters
 */

#pragma once
//#ifndef PERSON_H_
//#define PERSON_H_

#include <string>		// std::string

// Namespace edu::neu::csye6200

namespace edu {
namespace neu {
namespace csye6205 {

extern void functionFoo();

class Person {
private:
	int age = 0;
	std::string name = "Dan";
public:
	/*
	 * Static data member of class
	 * Declared in the class header (.h) file
	 * (Name and Type announced to compiler so no compiler error)
	 * Declaration is announcement to Compiler
	 * (but no memory is allocated for storing data and no initialization is possible)
	 */
	static int version;	// Declaration only, must Define in .cpp
	/**
	 * Default Class Constructor
	 */
	Person();	// specification only (like Java abstract method or java interface
	/**
	 * Default Class Constructor
	 */
//	Person(int age, std::string name);
	Person(int _age, std::string _name) : age(_age), name(_name) {
	}

	virtual ~Person();

	std::string toString();

	static Person demo();	// demonstrate class usage
//	static void demo();	// demonstrate class usage
}; // C++ class specification is a statement and must terminate in semicolon ";"

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

//#endif /* PERSON_H_ */

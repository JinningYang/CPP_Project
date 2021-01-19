	/*
 * circle.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: dgpeters
 */

#include "circle.h"

namespace edu {
namespace neu {
namespace csye6205 {

circle::circle() {
	// TODO Auto-generated constructor stub

}

circle::~circle() {
	// TODO Auto-generated destructor stub
}

void circle::info() {
	std::cout  << this->description
			<< " ID= " << id
			<< " version " << this->version
			<< std::endl;
}

void circle::demo() {
	std::cout << "\n\t circle::demo()..." << std::endl;

	/**
	 * 1. Create shape object (s) on stack
	 * 2. Create s_ptr pointer variable on stack
	 */
	shape s, *s_ptr;
//	shape s;
//	shape *s_ptr = &s;
	/**
	 * Use shape object
	 */
	s.info();
	/**
	 * assign address of shape object (s) to shape pointer (s_ptr)
	 */
	s_ptr = &s;
	/**
	 * Use shape object (s) via shape pointer (s_ptr)
	 */
	s_ptr->info();

	/**
	 * Create a circle object (c) on the stack
	 */
	circle c;
	c.info();	// use circle object
	/**
	 * Assign address of circle object (c) to shape pointer (s_ptr)
	 */
	s_ptr = &c;	// circle IS-A shape because circle class inherits from shape class

	/**
	 * Using a derived object (circle derived from shape)
	 * with a base class pointer (shape pointer s_ptr)
	 * allows for polymorphism (if derived class overrides base class method).
	 */
	s_ptr->info();	// use circle object (c) through shape pointer (s_ptr)

	std::cout << "\n\t circle::demo()... done!" << std::endl;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

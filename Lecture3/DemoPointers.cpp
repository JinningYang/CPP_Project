/*
 * DemoPointers.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: dgpeters
 */

#include <iostream>			// std::cout, std::endl, std::cerr
#include <sstream>			// std::stringstream

#include "DemoPointers.h"

namespace edu {
namespace neu {
namespace csye6205 {

DemoPointers::DemoPointers() : intData(1) {
}

DemoPointers::~DemoPointers() {
}

/**
 * return a string representation object state
 */
std::string DemoPointers::toString() {
//	/*
//	 * Create a stringstream object on the heap
//	 */
//	std::stringstream *ss =  new std::stringstream();
//
//	/* create string
//	 */
//	*ss << this->intData;
//
//	return ss->str();
	/*
	 * Create a stringstream object on the stack
	 */
	std::stringstream ss;

	/* create string
	 */
	ss << this->intData;

	return ss.str();
}

void DemoPointers::useDataPointers() {
	std::cout << "\n\t DemoPointers::useDataPointers()..." << std::endl;

	/* primitive int value assigned to int variable (memory location named) n
	 */
	int n = 0;
	/* address of variable n assigned to pointer variable ptr
	 */
	int *ptr = &n;
	/* show value in n is same as in location pointed to by ptr
	 */
	std::cout << " -- show value in n is same as in location pointed to by ptr..." << std::endl;
	std::cout << " n [*ptr] = " << n << " [" << *ptr << "]" << std::endl;

	/* show UPDATED value in n is same as in location pointed to by ptr because it points to the same location
	 */
	n++;	// increment value in n
	std::cout << " -- show UPDATED value in n is same as in location pointed to by ptr because it points to the same location..." << std::endl;
	std::cout << " n [*ptr] = " << n << " [" << *ptr << "]" << std::endl;

	/* show UPDATED value in n is same as in location pointed to by ptr because it points to the same location
	 */
	n = 3;	// assign 3 in n
	std::cout << " -- show UPDATED value in n is same as in location pointed to by ptr because it points to the same location..." << std::endl;
	std::cout << " n [*ptr] = " << n << " [" << *ptr << "]" << std::endl;

	std::cout << "\n\t DemoPointers::useDataPointers()... done!" << std::endl;
}

void DemoPointers::useObjectPointers() {
	std::cout << "\n\t DemoPointers::useObjectPointers()..." << std::endl;

	/* address of object "this" assigned to pointer variable ptr
	 */
	DemoPointers *ptr = this;	// "this" object pointer

	/* show value in n is same as in location pointed to by ptr
	 */
	std::cout << " -- show value in n is same as in location pointed to by ptr..." << std::endl;
	std::cout << " this->toString() [ptrtoString()] = " << this->toString() << " [" << ptr->toString() << "]" << std::endl;

	/* show UPDATED value in n is same as in location pointed to by ptr because it points to the same location
	 */
	this->intData++;	// increment value in intData
	std::cout << " -- show UPDATED value in n is same as in location pointed to by ptr because it points to the same location..." << std::endl;
	std::cout << " this->toString() [ptr->toString()] = " << this->toString() << " [" << ptr->toString() << "]" << std::endl;

	/* show UPDATED value in n is same as in location pointed to by ptr because it points to the same location
	 */
	this->intData = 3;	// increment value in n
	std::cout << " -- show UPDATED value in n is same as in location pointed to by ptr because it points to the same location..." << std::endl;
	std::cout << " this->toString() [ptr->toString()] = " << this->toString() << " [" << ptr->toString() << "]" << std::endl;

	/**
	 * instantiate (create) object from class DemoPointers on heap memory
	 */
	ptr = new DemoPointers();
	std::cout << " -- instantiate (create) object from class DemoPointers on heap memory..." << std::endl;
	std::cout << " [ptr->toString()] = " << " [" << ptr->toString() << "]" << std::endl;

	/* show UPDATED value in n is same as in location pointed to by ptr because it points to the same location
	 */
	ptr->intData++;	// increment value in intData
	std::cout << " -- show UPDATED value in object..." << std::endl;
	std::cout << " [ptr->toString()] = " << " [" << ptr->toString() << "]" << std::endl;

	/* show UPDATED value in n is same as in location pointed to by ptr because it points to the same location
	 */
	ptr->intData = 3;	// increment value in n
	std::cout << " -- show UPDATED value in object..." << std::endl;
	std::cout << " [ptr->toString()] = " << " [" << ptr->toString() << "]" << std::endl;

	/**
	 *
	 */
	delete ptr;
	ptr = nullptr;

	std::cout << "\n\t DemoPointers::useObjectPointers()... done!" << std::endl;
}

void DemoPointers::useArrayPointers() {
	std::cout << "\n\t DemoPointers::useArrayPointers()..." << std::endl;

	/**
	 * array of characters
	 * (char values in contiguous memory)
	 */
	char charArray[] = { 'm', 'a', 'i', 'n' };
	const int K_SIZE_CHAR_ARRAY = sizeof(charArray)/sizeof(char);
//	char *ptr = &charArray[0];	// assign address of array to array pointer
	char *ptr = charArray;	// assign address of array to array pointer

	std::cout << K_SIZE_CHAR_ARRAY << " characters in array." << std::endl;
	for (char c : charArray) {
		std::cout << c;
	}
	std::cout << std::endl;

	for (int i=0; i < K_SIZE_CHAR_ARRAY; i++) {
//		std::cout << *(ptr+i);		// pointers can be used as array
		std::cout << ptr[i];	// pointers can be used as array
	}
	std::cout << std::endl;

	std::cout << "\n\t DemoPointers::useArrayPointers()... done!" << std::endl;
}


/**
 * demonstrate the use of this class
 */
void DemoPointers::demo() {
	std::cout << "\n\t DemoPointers::demo()..." << std::endl;

	/* instantiate object from DemoPointers class on stack (automatic) memory
	 */
	DemoPointers obj;
	DemoPointers *ptr = &obj;
	/*
	 * call member methods using object
	 */
	obj.useDataPointers();
	ptr->useObjectPointers(); // call class member method from pointer to object
	obj.useArrayPointers(); // call class member method from object

	std::cout << "\n\t DemoPointers::demo()... done!" << std::endl;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

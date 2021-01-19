/*
 * Animal.cpp
 *
 *  Created on: Sep 17, 2017
 *      Author: danielgmp
 */
#include "Parent.h"

#include <iostream>

using namespace std;

namespace edu {
namespace neu {
namespace csye6205 {

Parent::Parent() : name("parent"){
}

Parent::Parent(string name) : name(name){
}

Parent::~Parent() {
}

const string& Parent::getName() const {
	return name;
}

void Parent::setName(const string& name) {
	this->name = name;
}

void Parent::speak() {
	cout << "My name is " << this->name << " and I am the Parent."  << endl;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

/*
 * PersonFactory.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include "PersonFactory.h"
#include "Person.h"

namespace edu {
namespace neu {
namespace csye6205 {

PersonFactory::PersonFactory() {
}

PersonFactory::~PersonFactory() {
}
AbstractPersonAPI * PersonFactory::getObject() {
	return new Person();
}
AbstractPersonAPI * PersonFactory::getObject(std::string csvData) {
	return new Person(csvData);
}
void PersonFactory::freeObject(AbstractPersonAPI * p) {
	delete p;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

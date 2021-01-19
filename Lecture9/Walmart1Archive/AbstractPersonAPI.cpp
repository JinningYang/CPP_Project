/*
 * AbstractPerson.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include "AbstractPersonAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

AbstractPersonAPI::AbstractPersonAPI() {
}
AbstractPersonAPI::~AbstractPersonAPI() {
}
/**
 * Comparators
 */
bool AbstractPersonAPI::comparePersonID(AbstractPersonAPI *p1, AbstractPersonAPI *p2) {
	return p1->getId() < p2->getId();
}
bool AbstractPersonAPI::comparePersonAge(AbstractPersonAPI *p1, AbstractPersonAPI *p2) {
	return p1->getAge() < p2->getAge();
}
bool AbstractPersonAPI::comparePersonFirstName(AbstractPersonAPI *p1, AbstractPersonAPI *p2) {
	return p1->getFirstName() < p2->getFirstName();
}
bool AbstractPersonAPI::comparePersonLastName(AbstractPersonAPI *p1, AbstractPersonAPI *p2) {
	return p1->getLastName() < p2->getLastName();
}

bool comparePersonID(AbstractPersonAPI *p1, AbstractPersonAPI *p2) {
	return p1->getId() < p2->getId();
}
bool comparePersonAge(AbstractPersonAPI *p1, AbstractPersonAPI *p2) {
	return p1->getAge() < p2->getAge();
}
bool comparePersonFirstName(AbstractPersonAPI *p1, AbstractPersonAPI *p2) {
	return p1->getFirstName() < p2->getFirstName();
}
bool comparePersonLastName(AbstractPersonAPI *p1, AbstractPersonAPI *p2) {
	return p1->getLastName() < p2->getLastName();
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

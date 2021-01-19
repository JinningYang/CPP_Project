/*
 * AbstractItemAPI.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include "AbstractItemAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

AbstractItemAPI::AbstractItemAPI() {
}
AbstractItemAPI::~AbstractItemAPI() {
}
/**
 * Comparators
 */
bool AbstractItemAPI::compareItemID(AbstractItemAPI *p1, AbstractItemAPI *p2) {
	return p1->getId() < p2->getId();
}
bool AbstractItemAPI::compareItemPrice(AbstractItemAPI *p1, AbstractItemAPI *p2) {
	return p1->getPrice() < p2->getPrice();
}
bool AbstractItemAPI::compareItemName(AbstractItemAPI *p1, AbstractItemAPI *p2) {
	return p1->getName() < p2->getName();
}

bool compareItemID(AbstractItemAPI *p1, AbstractItemAPI *p2) {
	return p1->getId() < p2->getId();
}
bool compareItemPrice(AbstractItemAPI *p1, AbstractItemAPI *p2) {
	return p1->getPrice() < p2->getPrice();
}
bool compareItemName(AbstractItemAPI *p1, AbstractItemAPI *p2) {
	return p1->getName() < p2->getName();
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

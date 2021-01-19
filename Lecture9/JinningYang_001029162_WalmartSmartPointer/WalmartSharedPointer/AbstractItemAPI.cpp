#ifndef ABSTRACTITEMAPI_CPP_INCLUDED
#define ABSTRACTITEMAPI_CPP_INCLUDED

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
bool AbstractItemAPI::compareItemID(std::shared_ptr<AbstractItemAPI> p1, std::shared_ptr<AbstractItemAPI> p2) {
	return p1->getId() < p2->getId();
}
bool AbstractItemAPI::compareItemPrice(std::shared_ptr<AbstractItemAPI> p1, std::shared_ptr<AbstractItemAPI> p2) {
	return p1->getPrice() < p2->getPrice();
}
bool AbstractItemAPI::compareItemName(std::shared_ptr<AbstractItemAPI> p1, std::shared_ptr<AbstractItemAPI> p2) {
	return p1->getName() < p2->getName();
}

bool compareItemID(std::shared_ptr<AbstractItemAPI> p1, std::shared_ptr<AbstractItemAPI> p2) {
	return p1->getId() < p2->getId();
}
bool compareItemPrice(std::shared_ptr<AbstractItemAPI> p1, std::shared_ptr<AbstractItemAPI> p2) {
	return p1->getPrice() < p2->getPrice();
}
bool compareItemName(std::shared_ptr<AbstractItemAPI> p1, std::shared_ptr<AbstractItemAPI> p2) {
	return p1->getName() < p2->getName();
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */


#endif // ABSTRACTITEMAPI_CPP_INCLUDED

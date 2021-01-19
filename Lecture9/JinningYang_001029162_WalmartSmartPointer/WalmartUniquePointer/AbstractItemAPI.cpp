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
bool AbstractItemAPI::compareItemID(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2) {
	return p1->getId() < p2->getId();
}
bool AbstractItemAPI::compareItemPrice(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2) {
	return p1->getPrice() < p2->getPrice();
}
bool AbstractItemAPI::compareItemName(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2) {
	return p1->getName() < p2->getName();
}

bool compareItemID(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2) {
	return p1->getId() < p2->getId();
}
bool compareItemPrice(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2) {
	return p1->getPrice() < p2->getPrice();
}
bool compareItemName(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2) {
	return p1->getName() < p2->getName();
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

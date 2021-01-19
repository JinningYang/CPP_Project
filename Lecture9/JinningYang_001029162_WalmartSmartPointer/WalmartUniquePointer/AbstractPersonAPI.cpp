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
bool AbstractPersonAPI::comparePersonID(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2) {
	return p1->getId() < p2->getId();
}
bool AbstractPersonAPI::comparePersonAge(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2) {
	return p1->getAge() < p2->getAge();
}
bool AbstractPersonAPI::comparePersonFirstName(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2) {
	return p1->getFirstName() < p2->getFirstName();
}
bool AbstractPersonAPI::comparePersonLastName(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2) {
	return p1->getLastName() < p2->getLastName();
}

bool comparePersonID(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2) {
	return p1->getId() < p2->getId();
}
bool comparePersonAge(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2) {
	return p1->getAge() < p2->getAge();
}
bool comparePersonFirstName(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2) {
	return p1->getFirstName() < p2->getFirstName();
}
bool comparePersonLastName(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2) {
	return p1->getLastName() < p2->getLastName();
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

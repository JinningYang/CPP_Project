/*
 * GroceryItemFactory.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: dgpeters
 */

#include "GroceryItemFactory.h"
#include "Item.h"

namespace edu {
namespace neu {
namespace csye6205 {

GroceryItemFactory::GroceryItemFactory() {
}
GroceryItemFactory::~GroceryItemFactory() {
}
AbstractItemAPI * GroceryItemFactory::getObject() {
	return new Item();
}
AbstractItemAPI * GroceryItemFactory::getObject(std::string csvData) {
	return new Item(csvData);
}
void GroceryItemFactory::freeObject(AbstractItemAPI * p) {
	delete p;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

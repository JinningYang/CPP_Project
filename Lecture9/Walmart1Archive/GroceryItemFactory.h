/*
 * GroceryItemFactory.h
 *
 *  Created on: Nov 11, 2020
 *      Author: dgpeters
 */

#ifndef GROCERYITEMFACTORY_H_
#define GROCERYITEMFACTORY_H_

#include "AbstractItemFactoryAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class GroceryItemFactory: public AbstractItemFactoryAPI {
public:
	GroceryItemFactory();
	virtual ~GroceryItemFactory();
	AbstractItemAPI * getObject();
	AbstractItemAPI * getObject(std::string csvData);
	void freeObject(AbstractItemAPI * p);
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* GROCERYITEMFACTORY_H_ */

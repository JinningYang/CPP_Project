/*
 * AbstractItemFactoryAPI.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef ABSTRACTITEMFACTORYAPI_H_
#define ABSTRACTITEMFACTORYAPI_H_

#include <string>					// std::string
#include "AbstractItemAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractItemFactoryAPI {
public:
	AbstractItemFactoryAPI();
	virtual ~AbstractItemFactoryAPI();
	virtual AbstractItemAPI * getObject() = 0;
	virtual AbstractItemAPI * getObject(std::string) = 0;
	virtual void freeObject(AbstractItemAPI * p) = 0;
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* ABSTRACTITEMFACTORYAPI_H_ */

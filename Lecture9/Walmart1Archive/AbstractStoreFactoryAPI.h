/*
 * AbstractStoreFactoryAPI.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef ABSTRACTSTOREFACTORYAPI_H_
#define ABSTRACTSTOREFACTORYAPI_H_

#include <string>					// std::string
#include "AbstractStoreAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractStoreFactoryAPI {
public:
	AbstractStoreFactoryAPI();
	virtual ~AbstractStoreFactoryAPI();
	virtual AbstractStoreAPI * getObject() = 0;
	virtual AbstractStoreAPI * getObject(std::string) = 0;
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* ABSTRACTSTOREFACTORYAPI_H_ */

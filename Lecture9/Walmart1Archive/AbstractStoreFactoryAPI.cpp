/*
 * AbstractStoreFactoryAPI.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include "Store.h"
#include "AbstractStoreFactoryAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

AbstractStoreFactoryAPI::AbstractStoreFactoryAPI() {
}
AbstractStoreFactoryAPI::~AbstractStoreFactoryAPI() {
}
AbstractStoreAPI * AbstractStoreFactoryAPI::getObject() {
	return new Store();
}
AbstractStoreAPI * AbstractStoreFactoryAPI::getObject(std::string csvData) {
	return new Store(csvData);
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

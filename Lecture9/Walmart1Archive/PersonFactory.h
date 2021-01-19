/*
 * PersonFactory.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef PERSONFACTORY_H_
#define PERSONFACTORY_H_

#include "AbstractPersonFactoryAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class PersonFactory: public AbstractPersonFactoryAPI {
public:
	PersonFactory();
	virtual ~PersonFactory();

	AbstractPersonAPI * getObject();
	AbstractPersonAPI * getObject(std::string csvData);
	void freeObject(AbstractPersonAPI * );
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* PERSONFACTORY_H_ */

#ifndef ABSTRACTPERSONFACTORYAPI_H_INCLUDED
#define ABSTRACTPERSONFACTORYAPI_H_INCLUDED

#include <string>					// std::string
#include "AbstractPersonAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractPersonFactoryAPI {
public:
	AbstractPersonFactoryAPI();
	virtual ~AbstractPersonFactoryAPI();

	virtual AbstractPersonAPI * getObject() = 0;
	virtual AbstractPersonAPI * getObject(std::string) = 0;
	virtual void freeObject(AbstractPersonAPI *) = 0;
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif // ABSTRACTPERSONFACTORYAPI_H_INCLUDED

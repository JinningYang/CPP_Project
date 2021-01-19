#ifndef ABSTRACTPERSONFACTORYAPI_H_INCLUDED
#define ABSTRACTPERSONFACTORYAPI_H_INCLUDED

#include <string>					// std::string
#include <memory>
#include "AbstractPersonAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractPersonFactoryAPI {
public:
	AbstractPersonFactoryAPI();
	virtual ~AbstractPersonFactoryAPI();

	virtual std::shared_ptr<AbstractPersonAPI> getObject() = 0;
	virtual std::shared_ptr<AbstractPersonAPI> getObject(std::string) = 0;
	virtual void freeObject(AbstractPersonAPI *) = 0;
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */


#endif // ABSTRACTPERSONFACTORYAPI_H_INCLUDED

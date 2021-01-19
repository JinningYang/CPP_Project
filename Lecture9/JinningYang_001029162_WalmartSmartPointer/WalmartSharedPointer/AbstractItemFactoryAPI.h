#ifndef ABSTRACTITEMFACTORYAPI_H_INCLUDED
#define ABSTRACTITEMFACTORYAPI_H_INCLUDED

#include <string>					// std::s
#include <memory>
#include "AbstractItemAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractItemFactoryAPI {
public:
	AbstractItemFactoryAPI();
	virtual ~AbstractItemFactoryAPI();
	virtual std::shared_ptr<AbstractItemAPI> getObject() = 0;
	virtual std::shared_ptr<AbstractItemAPI> getObject(std::string) = 0;
	virtual void freeObject(AbstractItemAPI * p) = 0;
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */


#endif // ABSTRACTITEMFACTORYAPI_H_INCLUDED

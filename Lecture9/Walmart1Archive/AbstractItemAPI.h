/*
 * AbstractItemPI.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef ABSTRACTITEMAPI_H_
#define ABSTRACTITEMAPI_H_

#include <string>				// std::string

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractItemAPI;

typedef bool (*CompareItemPtrs_t)(AbstractItemAPI *, AbstractItemAPI *);

/**
 * AbstractItemAPI for each Item object
 */
class AbstractItemAPI {
public:
	AbstractItemAPI();
	virtual ~AbstractItemAPI();

	virtual int getId() const = 0;
	virtual void setId(int id) = 0;

	virtual const std::string& getName() const = 0;
	virtual void setName(const std::string &name) = 0;

	virtual double getPrice() const = 0;
	virtual void setPrice(double price) = 0;

	virtual std::string toString() = 0;

	static bool compareItemID(AbstractItemAPI *item1, AbstractItemAPI *item2);
	static bool compareItemPrice(AbstractItemAPI *item1, AbstractItemAPI *item2);
	static bool compareItemName(AbstractItemAPI *item1, AbstractItemAPI *item2);
};

/**
 * Comparators
 */
bool compareItemID(AbstractItemAPI *item1, AbstractItemAPI *item2);
bool compareItemPrice(AbstractItemAPI *item1, AbstractItemAPI *item2);
bool compareItemName(AbstractItemAPI *item1, AbstractItemAPI *item2);

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* ABSTRACTITEMAPI_H_ */

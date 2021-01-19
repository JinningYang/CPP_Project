/*
 * AbstractPerson.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef ABSTRACTPERSONAPI_H_
#define ABSTRACTPERSONAPI_H_

#include <string>				// std::string

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractPersonAPI;
class Item;

typedef bool (*CompareAbstractPersonPtrs_t)(AbstractPersonAPI *, AbstractPersonAPI *);

class AbstractPersonAPI {
public:
	AbstractPersonAPI();
	virtual ~AbstractPersonAPI();

	virtual int getAge() const = 0;
	virtual void setAge(int age) = 0;
	virtual const std::string& getFirstName() const = 0;
	virtual void setFirstName(const std::string &firstName) = 0;
	virtual int getId() const = 0;
	virtual void setId(int id) = 0;
	virtual const std::string& getLastName() const = 0;
	virtual void setLastName(const std::string &lastName) = 0;

	virtual const std::string toString() const = 0;
	static bool comparePersonID(AbstractPersonAPI *p1, AbstractPersonAPI *p2);
	static bool comparePersonAge(AbstractPersonAPI *p1, AbstractPersonAPI *p2);
	static bool comparePersonFirstName(AbstractPersonAPI *p1, AbstractPersonAPI *p2);
	static bool comparePersonLastName(AbstractPersonAPI *p1, AbstractPersonAPI *p2);
};

/**
 * Comparators
 */
bool comparePersonID(AbstractPersonAPI *p1, AbstractPersonAPI *p2);
bool comparePersonAge(AbstractPersonAPI *p1, AbstractPersonAPI *p2);
bool comparePersonFirstName(AbstractPersonAPI *p1, AbstractPersonAPI *p2);
bool comparePersonLastName(AbstractPersonAPI *p1, AbstractPersonAPI *p2);

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* ABSTRACTPERSONAPI_H_ */

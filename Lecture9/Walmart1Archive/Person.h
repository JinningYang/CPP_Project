/*
 * Person.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <sstream>		// stringstream
#include "AbstractPersonAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class Person: public AbstractPersonAPI {
private:
	int id;
	int age;
	std::string firstName;
	std::string lastName;

public:
	Person();
	Person(std::string csvData);
	Person(int id, int age, std::string firstName, std::string lastName);
	virtual ~Person();
	std::stringstream parsePerson(std::string csvData);

	int getAge() const;
	void setAge(int age);
	const std::string& getFirstName() const;
	void setFirstName(const std::string &firstName);
	int getId() const;
	void setId(int id);
	const std::string& getLastName() const;
	void setLastName(const std::string &lastName);
	const std::string toString() const;
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* PERSON_H_ */

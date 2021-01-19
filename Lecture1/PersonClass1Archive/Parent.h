/*
 * Animal.h
 *
 *  Created on: Sep 17, 2017
 *      Author: danielgmp
 */

#ifndef PARENT_H_
#define PARENT_H_

#include <string>

using namespace std;

namespace edu {
namespace neu {
namespace csye6205 {

class Parent {
private:
	string name;
public:
	Parent();
	Parent(string name);
	virtual ~Parent();

	const string& getName() const;
	void setName(const string& name);
	virtual void speak();
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* PARENT_H_ */

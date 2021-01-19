/*
 * DemoPointers.h
 *
 *  Created on: Sep 22, 2020
 *      Author: dgpeters
 */

#ifndef DEMOPOINTERS_H_
#define DEMOPOINTERS_H_

#include <string>		// std::string

namespace edu {
namespace neu {
namespace csye6205 {

class DemoPointers {
private:
	int intData = 0;

public:
	DemoPointers();
	virtual ~DemoPointers();

	void useDataPointers();
	void useArrayPointers();
	void useObjectPointers();
	std::string toString();

	/**
	 * demonstrate the use of this class
	 */
	static void demo();
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* DEMOPOINTERS_H_ */

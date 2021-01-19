/*
 * circle.h
 *
 *  Created on: Sep 22, 2020
 *      Author: dgpeters
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>		// std::cout, std::endl, std::cerr
#include <string>		// std::string
#include "shape.h"

namespace edu {
namespace neu {
namespace csye6205 {

class circle: public shape {
private:
	static const int id = 2;
	const std::string version = "1.00.00";
	const std::string description = "I am a Circle!";
public:
	circle();
	virtual ~circle();
	/**
	 * implement exact same method as base class to override it
	 */
	virtual void info() override;
	static void demo();
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* CIRCLE_H_ */

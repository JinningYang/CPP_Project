/*
 * shape.h
 *
 *  Created on: Sep 22, 2020
 *      Author: dgpeters
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>		// std::cout, std::endl, std::cerr
#include <string>		// std::string

namespace edu {
namespace neu {
namespace csye6205 {

class shape {
private:
	static const int id = 1;
	const std::string version = "1.00.00";
	const std::string description = "I am a Shape!";
public:
	shape();
	virtual ~shape();
	/*
	 * virtual is required to allow override by child
	 */
	virtual void info();
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* SHAPE_H_ */

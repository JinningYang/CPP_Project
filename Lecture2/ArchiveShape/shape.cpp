/*
 * shape.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: dgpeters
 */

#include "shape.h"

namespace edu {
namespace neu {
namespace csye6205 {

shape::shape() {
	// TODO Auto-generated constructor stub

}

shape::~shape() {
	// TODO Auto-generated destructor stub
}

void shape::info() {
	std::cout  << this->description
			<< " ID= " << id
			<< " version " << this->version
			<< std::endl;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

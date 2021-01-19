/*
 * Walmart.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef WALMART_H_
#define WALMART_H_

#include "Store.h"

namespace edu {
namespace neu {
namespace csye6205 {

class Walmart: public Store {
public:
	Walmart();
	Walmart(int id, std::string name);
	virtual ~Walmart();

	static void demo();
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* WALMART_H_ */

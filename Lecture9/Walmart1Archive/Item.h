/*
 * Item.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <sstream>			// std::stringstream
#include "AbstractItemAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class Item: public AbstractItemAPI {
private:
	int id;
	double price;
	std::string name;
public:
	Item();
	Item(int id, double price, std::string name);
	Item(std::string csvData);
	virtual ~Item();

	std::stringstream parseItem(std::string csvData);

	virtual int getId() const override;
	virtual void setId(int id) override;

	virtual const std::string& getName() const override;
	virtual void setName(const std::string &name) override;

	virtual double getPrice() const override;
	virtual void setPrice(double price) override;

	virtual std::string toString() override;
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* ITEM_H_ */

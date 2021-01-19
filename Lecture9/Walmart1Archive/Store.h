/*
 * Store.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef STORE_H_
#define STORE_H_

#include <vector>						// std::vector
#include "AbstractStoreAPI.h"

namespace edu {
namespace neu {
namespace csye6205 {

class Store : public AbstractStoreAPI {
private:
	int id;
	std::string name;
	std::vector< AbstractPersonAPI * > * pEmployees = nullptr;
	std::vector<AbstractItemAPI*> * pInventory = nullptr;

public:
	Store();
	Store(int id, std::string name);
	Store(std::string csvData);
	virtual ~Store();

	std::stringstream parseStore(std::string csvData);

	virtual int getId() const;
	virtual void setId(int id);
	virtual const std::string& getName() const;
	virtual void setName(const std::string &name);

	virtual void addEmployees(AbstractPersonAPI* p);
	virtual void addInventory(AbstractItemAPI *e);
	virtual std::string getInventoryInfo();
	virtual std::string getEmployeeInfo();
	virtual void sortInventory(CompareItemPtrs_t c);
	virtual void sortEmployees(CompareAbstractPersonPtrs_t);
//	virtual void clearInventory();
//	virtual void showInventory();
	virtual void show();

	static void demo();
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* STORE_H_ */

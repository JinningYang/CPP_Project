#ifndef ABSTRACTSTOREAPI_H_INCLUDED
#define ABSTRACTSTOREAPI_H_INCLUDED

#include <string>				// std::string
#include "AbstractItemAPI.h"
#include "AbstractPersonAPI.h"
#include <memory>

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractStoreAPI {
public:
	AbstractStoreAPI();
	virtual ~AbstractStoreAPI();

	/**
	 * Store ID
	 */
	virtual int getId() const = 0;
	virtual void setId(int id) = 0;
	/**
	 * Store Name
	 */
	virtual const std::string& getName() const = 0;
	virtual void setName(const std::string &name) = 0;

	/**
	 * Add employees to Store
	 */
	virtual void addEmployees(std::shared_ptr<AbstractPersonAPI> p) = 0;
	/**
	 * Add items to Store inventory
	 */
	virtual void addInventory(std::shared_ptr<AbstractItemAPI> e) = 0;

	/**
	 * Sort by supplied comparator function
	 */
	virtual void sortInventory(CompareItemPtrs_t c) = 0;
	virtual void sortEmployees(CompareAbstractPersonPtrs_t c) = 0;

	/**
	 * return a string representation the entire Inventory
	 */
	virtual std::string getInventoryInfo() = 0;
	/**
	 * return a string representation all the Employee information
	 */
	virtual std::string getEmployeeInfo() = 0;
	/**
	 * Show Store object state (i.e. all employees and all Inventory)
	 */
	virtual void show() = 0;
};

/**
 * Given:
 * 1. class AbstractStoreAPI
 *
 * Implement the following:
 *
 * NOTE: 50 POINTS deducted for late or incorrect submission.
 *
 *  REQUIREMENTS:
 * Correct executable on-time submission to Canvas of a zipped Eclipse workspace
 * in the correct format,
 * FOR EXAMPLE: workspace_2020-3_dan_peters_walmart.zip
 *
 * NOTE: all CONSOLE OUTPUT must be pasted into the end of the DriverProject class as a comment.
 *
 * 1. 20 POINTS: class Item derived from class AbstractItemAPI.
 * 2. 10 POINTS: class Person derived from class AbstractPersonAPI.
 *
 * 3. 30 POINTS: class Store derived from AbstractStoreAPI
 *  a. use the following partial implementation:
 *
 *	class Store : public AbstractStoreAPI {
 *	private:
 *		int id;
 *		std::string name;
 *		std::vector<AbstractPersonAPI*> employees;
 *		std::vector<AbstractItemAPI*> inventory;
 *	};
 *
 *
 * 4. 40 POINTS: class Walmart derived from class Store and
 * create a Walmart::demo() method to perform the following:
 *
 * 	a. add the following inventory items to Walmart:
 * 		"2,1.49,Wonder Bread"
 * 		"4,3.49,Tropicana OJ"
 * 		"3,2.49,Hood 2% Milk"
 * 		"5,.89,Golden apples"
 * 		"6,1.89,Apricots"
 *
 * 	b. add the following employees to Walmart:
 * 		"1001,17,Dan,Peters"
 * 		"1003,19,Sam,Sneed"
 * 		"1002,29,Jane,Eyre"
 *
 * 	Using the above data, perform the following in the Walmart demo():
 *
 * 	c. Sort by employees by ID and Items by ID
 * 	d. Sort by employees by AGE and Items by Price
 * 	e. Sort by employees by First Name and Items by Name
 * 	f. Sort by employees by Last Name and Items by Name
 *
 * USE THE FOLLOWING WALMART DEMO partial implementation as an example:
 *
 * 	static void demo() {
 * 	 std::cout << "\n\t" << "Walmart::demo() starting...") << std::endl;
 *   {
 *
 *		. . .
 *
 * 		std::cout << "\n\t" << "Sort employees by ID and inventory by item ID." << std::endl;
 * 		walmart.sortEmployees(compareEmployeeIDFunction);
 * 		walmart.sortInventory(compareItemIDFunction);
 * 		walmart.show();
 * 		std::cout << "\n\t" << "Sort employees by AGE and inventory by item PRICE." << std::endl;
 * 		walmart.sortEmployees(compareEmployeeAgeFunction);
 * 		walmart.sortInventory(compareItemPriceFunction);
 * 		walmart.show();
 * 		std::cout << "\n\t" << "Sort employees by FIRST NAME and inventory by item NAME." << std::endl;
 * 		walmart.sortEmployees(compareEmployeeFirstNameFunction);
 * 		walmart.sortInventory(compareItemNameFunction);
 * 		walmart.show();
 * 		std::cout << "\n\t" << "Sort employees by LAST NAME and inventory by item NAME." << std::endl;
 * 		walmart.sortEmployees(compareEmployeeLastNameFunction);
 * 		walmart.sortInventory(compareItemNameFunction);
 * 		walmart.show();
 *
 *		. . .
 *
 *   }
 */
} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */


#endif // ABSTRACTSTOREAPI_H_INCLUDED

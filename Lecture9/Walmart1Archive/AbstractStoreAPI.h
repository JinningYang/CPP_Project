/*
 * AbstractStoreAPI.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef ABSTRACTSTOREAPI_H_
#define ABSTRACTSTOREAPI_H_

#include <string>				// std::string
#include "AbstractItemAPI.h"
#include "AbstractPersonAPI.h"

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
	virtual void addEmployees(AbstractPersonAPI* p) = 0;
	/**
	 * Add items to Store inventory
	 */
	virtual void addInventory(AbstractItemAPI *e) = 0;

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

#ifdef    PORT_FROM_JAVA
package edu.neu.csye6200;

/**
 * Store API must be implemened by Store class
 */
public abstract class AbstractStoreAPI {
	public abstract void show();
	public abstract String getInventoryInfo();
	public abstract void sortInventory(CompareItemPtrs_t c);
	public abstract void clearInventory();
	public abstract void showInventory();

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
	 * NOTE: all CONSOLE OUTPUT must be pasted into the end of the Driver class as a comment.
	 *
	 * 1. 35 POINTS: class Item.
	 * 2. 10 POINTS: class Electronics derived from class Item (Use GoF Factory Design Pattern).
	 * 3. 10 POINTS: class Bread derived from class Item (Use GoF Factory Design Pattern).
	 * 4. 10 POINTS: class LiteBread derived from class Bread (Use GoF Factory Design Pattern).
	 *
	 * 5. 20 POINTS: class Store derived from AbstractStore
	 *  a. use the following partial implementation:
	 *
	 *  	public void sortInventory() {
	 *  		this.inventory.sort(null);
	 *  	}
	 *
	 *  	public void showInventory() {
	 *  		System.out.println(this.getInventoryInfo());
	 *  	}
	 *
	 * 6. 15 POINTS: class Walmart derived from class Store (Use GoF Factory Design Pattern).
	 * 	a. create a demo1() method to add 4 Electronic items to Walmart and sort by Price (DO NOT USE COMPARATOR).
	 * 	a. create a demo2() method to add 4 Bread items to Walmart and sort by Item number (DO NOT USE COMPARATOR).
	 * 	b. create a demo3() method to add 4 HealthyBread items to Walmart and sort by Calories (DO NOT USE COMPARATOR).
	 *
	 * USE THE FOLLOWING WALMART DEMO partial implementation as an example:
	 *
	 * 	public static void demo() {
	 * 	 System.out.println("\n\t" + Walmart.class.getName() + ".demo() starting...");
	 *   {
	 * 		Store walmart = new Walmart(77, "Walmart");
	 *
	 * 		for (AbstractItemAPI p : newProducts) {
	 * 			walmart.addItem(p);
	 * 		}
	 * 		System.out.println("Sort inventory by item PRICE.");
	 * 		walmart.sortInventory();
	 * 		walmart.showInventory();
	 *   }
	 *   {
	 * 		Store walmart = new Walmart(77, "Walmart");
	 *
	 * 		for (AbstractItemAPI p : newProducts) {
	 * 			walmart.addItem(p);
	 * 		}
	 * 		System.out.println("Sort inventory by item NUMBER.");
	 * 		walmart.sortInventory();
	 * 		walmart.showInventory();
	 *   }
	 *   {
	 * 		Store walmart = new Walmart(77, "Walmart");
	 *
	 * 		for (AbstractItemAPI p : newProducts) {
	 * 			walmart.addItem(p);
	 * 		}
	 * 		System.out.println("Sort inventory by item CALORIES.");
	 * 		walmart.sortInventory();
	 * 		walmart.showInventory();
	 *   }
	 *   System.out.println("\n" + walmart.getClass().getName() + ".demo() done!");
	 * }
	 */
}
#endif // PORT_FROM_JAVA

#endif /* ABSTRACTSTOREAPI_H_ */

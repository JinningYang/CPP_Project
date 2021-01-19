/*
 * Walmart.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include <iostream>			// std::cout, std::endl, std::cerr
#include <sstream>			// std::stringstream
#include <algorithm>		// std::sort
#include "Store.h"
/*
 * Only needed for demo NOT using GoF factory pattern
 */
#include "Person.h"
#include "Item.h"

/*
 * Only needed for demo using GoF factory pattern
 */
#include "PersonFactory.h"
#include "GroceryItemFactory.h"

#include "Walmart.h"

namespace edu {
namespace neu {
namespace csye6205 {

Walmart::Walmart() : Store() {
}
Walmart::Walmart(int _id, std::string _name) : Store(_id, _name){
}
Walmart::~Walmart() {
}
/**
 * demonstrate the use of this class
 */
void Walmart::demo() {
	std::cout << "\n\t" << "Walmart::demo()..." << std::endl;
	{
		std::cout << "Demonstrate Walmart without using GoF Factory pattern..." << std::endl;
		Store walmart(121, "Walmart");

		/**
		 * Add Employees
		 */
		std::cout << "Add Employees..." << std::endl;
		walmart.addEmployees(new Person());
		walmart.addEmployees(new Person(1003, 19, "Sam", "Sneed"));
		walmart.addEmployees(new Person(1002, 29, "Jane", "Eyre"));

		/**
		 * Add Items to Inventory
		 */
		std::cout << "Add Items to Inventory..." << std::endl;

		walmart.addInventory(new Item());
		walmart.addInventory(new Item(2, 1.49, "Wonder Bread"));
		walmart.addInventory(new Item(4, 3.49, "Tropicana OJ"));
		walmart.addInventory(new Item(3, 2.49, "Hood 2% Milk"));
		walmart.addInventory(new Item(5, .89, "Golden apples"));
		walmart.addInventory(new Item(6, 1.89, "Apricots"));

		walmart.show();

		/**
		 * Sort by employees by ID and Items by ID
		 */
		std::cout << "\n\t" << "Sort by ID:" << std::endl;
		walmart.sortEmployees(comparePersonID);
		walmart.sortInventory(compareItemID);
		walmart.show();
		/**
		 * Sort by Age and Item Price:
		 */
		std::cout << "\n\t" << "Sort by Age and Item Price:" << std::endl;
		walmart.sortEmployees(comparePersonAge);
		walmart.sortInventory(compareItemPrice);
		walmart.show();
		/**
		 * Sort by First Name and Item Name:
		 */
		std::cout << "\n\t" << "Sort by First Name and Item Name:" << std::endl;
		walmart.sortEmployees(comparePersonFirstName);
		walmart.sortInventory(compareItemName);
		walmart.show();
		/**
		 * Sort by Last Name and Item Name:
		 */
		std::cout << "\n\t" << "Sort by Last Name and Item Name:" << std::endl;
		walmart.sortEmployees(comparePersonLastName);
		walmart.sortInventory(compareItemName);
		walmart.show();
	}
	{
		std::cout << "Demonstrate Walmart WITH the GoF Factory pattern..." << std::endl;
		Store walmart(121, "Walmart");

		/**
		 * Add Employees
		 */
		std::cout << "Add Employees..." << std::endl;
		AbstractPersonFactoryAPI *personFactory = new PersonFactory();
		walmart.addEmployees(personFactory->getObject());
		walmart.addEmployees(personFactory->getObject("1003,19,Sam,Sneed"));
		walmart.addEmployees(personFactory->getObject("1002,29,Jane,Eyre"));

		/**
		 * Add Items to Inventory
		 */
		std::cout << "Add Items to Inventory..." << std::endl;
		AbstractItemFactoryAPI *groceryFactory = new GroceryItemFactory();

		walmart.addInventory(groceryFactory->getObject());
		walmart.addInventory(groceryFactory->getObject("2,1.49,Wonder Bread"));
		walmart.addInventory(groceryFactory->getObject("4,3.49,Tropicana OJ"));
		walmart.addInventory(groceryFactory->getObject("3,2.49,Hood 2% Milk"));
		walmart.addInventory(groceryFactory->getObject("5,.89,Golden apples"));
		walmart.addInventory(groceryFactory->getObject("6,1.89,Apricots"));

		walmart.show();

		/**
		 * Sort by employees by ID and Items by ID
		 */
		std::cout << "\n\t" << "Sort by ID:" << std::endl;
		walmart.sortEmployees(comparePersonID);
		walmart.sortInventory(compareItemID);
		walmart.show();
		/**
		 * Sort by Age and Item Price:
		 */
		std::cout << "\n\t" << "Sort by Age and Item Price:" << std::endl;
		walmart.sortEmployees(comparePersonAge);
		walmart.sortInventory(compareItemPrice);
		walmart.show();
		/**
		 * Sort by First Name and Item Name:
		 */
		std::cout << "\n\t" << "Sort by First Name and Item Name:" << std::endl;
		walmart.sortEmployees(comparePersonFirstName);
		walmart.sortInventory(compareItemName);
		walmart.show();
		/**
		 * Sort by Last Name and Item Name:
		 */
		std::cout << "\n\t" << "Sort by Last Name and Item Name:" << std::endl;
		walmart.sortEmployees(comparePersonLastName);
		walmart.sortInventory(compareItemName);
		walmart.show();
	}

	std::cout << "\n\t" << "Walmart::demo()... done!" << std::endl;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

/*
 * Store.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include <iostream>			// std::cout, std::endl, std::cerr
#include <sstream>			// std::stringstream
#include <algorithm>		// std::sort
#include "Store.h"
#include "Person.h"
#include "Item.h"
#include "MyTokenizer.h"

#include <vector>		// std::vector
#if defined(_WIN32)		// Windows, mingw
#include <cstring>		// Windows MinGw strtok, getline
#include <cstdlib>		// Windows MinGW need atoi, atod
#endif  // WIN32

#define D_USE_STRTOI
#if defined (D_USE_STRTOI)
#include <stdlib.h>		// strtoi, strtod
#endif     // D_USE_STRTOI

namespace edu {
namespace neu {
namespace csye6205 {

Store::Store()
	: id(101), name("Walmart"),
	  pEmployees(new std::vector<AbstractPersonAPI*>()),
	  pInventory(new std::vector<AbstractItemAPI*>()) {
}
Store::Store(int id, std::string name)
	: id(id), name(name),
	  pEmployees(new std::vector<AbstractPersonAPI*>()),
	  pInventory(new std::vector<AbstractItemAPI*>())  {
}
Store::Store(std::string csvData) {
	  pEmployees = new std::vector<AbstractPersonAPI*>();
	  pInventory = new std::vector<AbstractItemAPI*>();
	  parseStore(csvData);
}
Store::~Store() {
	std::cout << "Store destructor: ...";
	for (auto p : *pEmployees) {
		delete p;
		pEmployees->pop_back();
	}
	std::cout << std::endl << this->pEmployees->size() << " store employees, ";
	delete pEmployees;
	pEmployees = nullptr;
	for (auto p : *pInventory) {
		delete p;
		pInventory->pop_back();
	}
	std::cout << std::endl << this->pInventory->size() << " items in store inventory." << std::endl;
	delete pInventory;
	pInventory = nullptr;
	std::cout << " ... done!" << std::endl;
}

int Store::getId() const {
	return this->id;
}
void Store::setId(int _id) {
	this->id = _id;
}
const std::string& Store::getName() const {
	return this->name;
}

/**
 * parseStudent
 * parse tokens from CSV string to initialize attributes of Student object.
 *
 * 			"ID,Name"
 * e.g.
 * 			"1,,Walmart"
 */
std::stringstream Store::parseStore(std::string csvData) {
	std::stringstream tokenizerDiagnosticOutputStream;
	std::vector<std::string> tokens;

	/**
	 * any one of these various tokenizing solutions will parse a CSV string
	 */
	tokenizerDiagnosticOutputStream  << " => " << std::endl ;

	tokens = MyTokenizer::tokenizeCSV(csvData, 6);
	for (auto s : tokens ) {
		tokenizerDiagnosticOutputStream << s << " , ";
	}
	tokenizerDiagnosticOutputStream << std::endl;

	tokens = MyTokenizer::stringStreamCSV1(csvData);
	for (auto s :  tokens) {
		tokenizerDiagnosticOutputStream << s << " , ";
	}
	tokenizerDiagnosticOutputStream << std::endl;

	tokens = MyTokenizer::stringStreamCSV2(csvData);
	for (auto s :  tokens) {
		tokenizerDiagnosticOutputStream << s << " , ";
	}
	tokenizerDiagnosticOutputStream << std::endl;

	tokens = MyTokenizer::stringStreamCSV3(csvData);
	for (auto s :  tokens) {
		tokenizerDiagnosticOutputStream << s << " , ";
	}
	tokenizerDiagnosticOutputStream << std::endl;

	/**
	 * use tokens to set Student attributes
	 * converting as required
	 */
#if defined(_WIN32)
	int id = atoi( tokens[0] );
#else
	int id = stoi(tokens[0]);
#endif  // WIN32
	this->setId(id);
	this->setName(tokens[1]);

	return tokenizerDiagnosticOutputStream;
}

void Store::setName(const std::string &_name) {
	this->name = _name;
}

void Store::addEmployees(AbstractPersonAPI* p) {
	this->pEmployees->push_back(p);
}
void Store::addInventory(AbstractItemAPI *e) {
	this->pInventory->push_back(e);
}
std::string Store::getInventoryInfo() {
	std::stringstream ss;

	for (auto e : *this->pInventory) {
		ss << e->toString() << "\n";
	}
	return ss.str();
}
std::string Store::getEmployeeInfo() {
	std::stringstream ss;

	for (auto e : *this->pEmployees) {
		ss << e->toString() << "\n";
	}
	return ss.str();
}
void Store::sortInventory(CompareItemPtrs_t c) {
	std::sort(std::begin(*this->pInventory),std::end(*this->pInventory), c);
//	std::sort(std::begin(this->inventory),std::end(this->inventory), compareItemID);
//	std::sort(std::begin(this->inventory),std::end(this->inventory), compareItemPrice);
//	std::sort(std::begin(this->inventory),std::end(this->inventory), compareItemName);
}
void Store::sortEmployees(CompareAbstractPersonPtrs_t c) {
	std::sort(std::begin(*this->pEmployees),std::end(*this->pEmployees), c);
//	std::sort(std::begin(this->employees),std::end(this->employees), comparePersonID);
//	std::sort(std::begin(this->employees),std::end(this->employees), Abstract::Person::comparePersonID);
}

//void Store::clearInventory() {
//
//}
//void Store::showInventory() {
//
//}

void Store::show() {
	std::cout << " Store: ID: \t#" << this->getId() << std::endl;
	std::cout << " Store: Name: \t" << this->getName() << std::endl;
	std::cout << this->pEmployees->size() << " employees." << std::endl;
	std::cout << this->getEmployeeInfo() << std::endl;
	std::cout << this->pInventory->size() << " items in inventory." << std::endl;
	std::cout << this->getInventoryInfo() << std::endl;
}
/**
 * demonstrate the use of this class
 */
void Store::demo() {
	std::cout << "\n\t" << "Store::demo()..." << std::endl;

	Store walmart(121, "Walmart");

	/**
	 * Add Employees
	 */
	std::cout << "Add Employees..." << std::endl;
	walmart.addEmployees(new Person());
	walmart.addEmployees(new Person("1003,19,Sam,Sneed"));
//	walmart.addEmployees(new Person(1003, 19, "Sam", "Sneed"));
	walmart.addEmployees(new Person(1002, 29, "Jane", "Eyre"));

	/**
	 * Add Items to Inventory
	 */
	std::cout << "Add Items to Inventory..." << std::endl;
	walmart.addInventory(new Item());
	walmart.addInventory(new Item("2,1.49,Wonder Bread"));
//	walmart.addInventory(new Item(2, 1.49, "Wonder Bread"));
	walmart.addInventory(new Item(4, 3.49, "Tropicana OJ"));
	walmart.addInventory(new Item(3, 2.49, "Hood 2% Milk"));
	walmart.addInventory(new Item(5, .89, "Golden apples"));
	walmart.addInventory(new Item(6, 1.89, "Apricots"));

	walmart.show();

	/**
	 * Sort by ID
	 */
	std::cout << "\n\t" << "Sort by ID:" << std::endl;
	walmart.sortEmployees(AbstractPersonAPI::comparePersonID);
	walmart.sortInventory(AbstractItemAPI::compareItemID);
	walmart.show();
	/**
	 * Sort by Age and Item Price:
	 */
	std::cout << "\n\t" << "Sort by Age and Item Price:" << std::endl;
	walmart.sortEmployees(AbstractPersonAPI::comparePersonAge);
	walmart.sortInventory(AbstractItemAPI::compareItemPrice);
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

	std::cout << "\n\t" << "Store::demo()... done!" << std::endl;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

/*
 * Item.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include <iostream>		// std::cout, std::endl, std::cerr
#include <sstream>		// std::stringstream
#include <string>		// std::string
#include <vector>		// std::vector
#include <exception>		// std::exception

#if defined(_WIN32)		// Windows, mingw
#include <cstring>		// Windows MinGw strtok, getline
#include <cstdlib>		// Windows MinGW need atoi, atod
#endif  // WIN32

#define D_USE_STRTOI
#if defined (D_USE_STRTOI)
#include <stdlib.h>		// strtoi, strtod
#endif     // D_USE_STRTOI

#include "Item.h"
#include "MyTokenizer.h"

namespace edu {
namespace neu {
namespace csye6205 {

Item::Item() : id(1), price(0.99), name("Some Item") {
}
Item::Item(int id, double price, std::string name) : id(id), price(price), name(name) {
}
Item::Item(std::string csvData) {
	parseItem(csvData);
}
Item::~Item() {
}


///**
// * tokenizeCSV
// * parse tokens from CSV string to initialize attributes of Student object.
// *
// * "lastName,firstName,ID,studentId,age,gpa"
// */
//std::vector<std::string> tokenizeCSV(std::string csvData, int ntokens) {
//	std::vector<std::string> tokens;
//	const char  *delimiter = ",";		// constant
//
//	std::cout << "tokenize using strtok: " << csvData << std::endl;
//
//	/*
//	 * convert std::string into a C language string
//	 * using a vector of characters,
//	 * with an added '\0' as a null termination for an end of string array.
//	 */
//	std::vector<char> csvString(std::begin(csvData), std::end(csvData));
////	std::vector<char> cString(csvData.begin(), csvData.end());
//	csvString.push_back('\0');  // null terminate
//
//	/**
//	 * Use '\0' terminated contiguous data array,
//	 * (the backing storage for vector container)
//	 * as C language string for parsing 6 tokens.
//	 */
//	tokens.push_back( strtok(csvString.data(), delimiter) );
//	for (int i=1; i < ntokens; i++) {
//		tokens.push_back( strtok(NULL, delimiter) );
//	}
//
//	return tokens;
//}
///**
// * stringStreamCSV1
// * parse tokens from CSV string to initialize attributes of Student object.
// */
//std::vector<std::string> stringStreamCSV1(std::string csvData) {
//	std::vector<std::string> tokens;
//	std::stringstream ss(csvData);
//	const char  delimiter = ',';		// constant
//	std::string token;
//
//	std::cout << "tokenize using stringStreamCSV1: " << csvData << std::endl;
//
//	while ( std::getline(ss, token, delimiter) ) {
//		tokens.push_back(token);
//	}
//
//	return tokens;
//}
//
///**
// * stringStreamCSV2
// * parse tokens from CSV string to initialize attributes of Student object.
// */
//std::vector<std::string> stringStreamCSV2(std::string csvData) {
//	std::vector<std::string> tokens;
//	char delimiterOld = ',';
//	char delimiterNew = ' ';
//	std::replace(csvData.begin(), csvData.end(), delimiterOld, delimiterNew);
//	std::stringstream ss(csvData);
//	std::string token;
//
//	std::cout << "tokenize using stringStreamCSV2: " << csvData << std::endl;
//
//	while ( std::getline(ss, token, delimiterNew) ) {
//		tokens.push_back(token);
//	}
//
//	return tokens;
//}
//
///**
// * stringStreamCSV3
// * parse tokens from CSV string to initialize attributes of Student object.
// */
//std::vector<std::string> stringStreamCSV3(std::string csvData) {
//	std::vector<std::string> tokens;
//	const char delimiterOld = ',';
//	const char delimiterNew = ' ';
//	std::replace(csvData.begin(), csvData.end(), delimiterOld, delimiterNew);
//	std::stringstream ss(csvData);
//	std::string token;
//
//	std::cout << "tokenize using stringStreamCSV3: " << csvData << std::endl;
//
//	for( std::string token; ss >> token; ) {
//		tokens.push_back(token);
//	}
//
//	return tokens;
//}

/**
 * parseItem
 * parse tokens from CSV string to initialize attributes of Student object.
 *
 * 			"ID,Price,Name"
 * e.g.
 * 			"1,0.99,bread"
 */
std::stringstream Item::parseItem(std::string csvData) {
	std::stringstream tokenizerDiagnosticOutputStream;
	std::vector<std::string> tokens;

	/**
	 * any one of these various tokenizing solutions will parse a CSV string
	 */
	tokenizerDiagnosticOutputStream  << " => " << std::endl ;

	tokens = MyTokenizer::stringStreamCSV1(csvData);
//	tokens = MyTokenizer::tokenizeCSV(csvData, 6);
	for (auto s :  tokens) {
		tokenizerDiagnosticOutputStream << s << " , ";
	}
	tokenizerDiagnosticOutputStream << std::endl;

	/**
	 * use tokens to set Student attributes
	 * converting as required
	 */
	int id = 0;
	double price = 0;
#if defined(_WIN32)
	try {
		id = atoi( tokens[0] );
	} catch (std::exception& e) {
		std::cerr << "INVALID STRING REPRESENTATION '" << tokens[0] << std::endl;
		std::cerr << e.what() << std::endl;
	}
	try {
		price = atod(  tokens[1] );
	} catch (std::exception& e) {
		std::cerr << "INVALID STRING REPRESENTATION '" << tokens[1] << std::endl;
		std::cerr << e.what() << std::endl;
	}
//	int studentId = atoi( tokens[2] );
//	double gpa = atod(  tokens[5] );
#else
	try {
		id = stoi(tokens[0]);
	} catch (std::exception& e) {
		std::cerr << "INVALID STRING REPRESENTATION '" << tokens[0] << std::endl;
		std::cerr << e.what() << std::endl;
	}
	try {
		price = stod( tokens[1] );
	} catch (std::exception& e) {
		std::cerr << "INVALID STRING REPRESENTATION '" << tokens[1] << std::endl;
		std::cerr << e.what() << std::endl;
	}

	//	double gpa  = stod( tokens[5] );
#endif  // WIN32
//#if defined(_WIN32)
//	int id = atoi( tokens[0] );
//	double price = atod(  tokens[1] );
//#else
//	int id = stoi(tokens[0]);
//	double price  = stod( tokens[1] );
//#endif  // WIN32
	this->setId(id);
	this->setPrice(price);
	this->setName(tokens[2]);



	return tokenizerDiagnosticOutputStream;
}

int Item::getId() const {
	return id;
}

void Item::setId(int id) {
	this->id = id;
}

const std::string& Item::getName() const {
	return name;
}

void Item::setName(const std::string &name) {
	this->name = name;
}

double Item::getPrice() const {
	return price;
}

void Item::setPrice(double price) {
	this->price = price;
}

std::string Item::toString() {
	std::stringstream ss;

	ss << "#" << this->getId();
	ss << " $" << this->getPrice();
	ss << " " << this->getName();

	return ss.str();
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

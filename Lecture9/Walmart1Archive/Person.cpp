/*
 * Person.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include <iostream>		// std::cout, std::endl, std::cerr
#include <sstream>		// std::stringstream
#include <vector>		// std::vector
#include <exception>	// std::exception

#if defined(_WIN32)		// Windows, mingw
#include <cstring>		// Windows MinGw strtok, getline
#include <cstdlib>		// Windows MinGW need atoi, atod
#endif  // WIN32

#define D_USE_STRTOI
#if defined (D_USE_STRTOI)
#include <stdlib.h>		// strtoi, strtod
#endif     // D_USE_STRTOI

#include "Person.h"
#include "MyTokenizer.h"

namespace edu {
namespace neu {
namespace csye6205 {

Person::Person() : id(1001), age(17), firstName("Dan"), lastName("Peters") {
}
Person::Person(int id, int age, std::string firstName, std::string lastName) : id(id), age(age), firstName(firstName), lastName(lastName) {
}
/**
 * construct using CSV string
 * "ID,firstName,lastName,age"
 * e.g.
 * "1,dan,peters,17"
 */
Person::Person(std::string csvData) {
	parsePerson(csvData);
}

Person::~Person() {
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
 * parseStudent
 * parse tokens from CSV string to initialize attributes of Student object.
 *
 * 			"ID,Age,firstName,lastName"
 * e.g.
 * 			"1,17,dan,peters"
 */
std::stringstream Person::parsePerson(std::string csvData) {
	std::stringstream tokenizerDiagnosticOutputStream;
	std::vector<std::string> tokens;

	/**
	 * any one of these various tokenizing solutions will parse a CSV string
	 */
	tokenizerDiagnosticOutputStream  << " => " << std::endl ;

	// CSV Data and number of tokens
//	tokens = MyTokenizer::tokenizeCSV(csvData, 6);
//	for (auto s : tokens ) {
//		tokenizerDiagnosticOutputStream << s << " , ";
//	}
//	tokenizerDiagnosticOutputStream << std::endl;

	tokens = MyTokenizer::stringStreamCSV1(csvData);
	for (auto s :  tokens) {
		tokenizerDiagnosticOutputStream << s << " , ";
	}
	tokenizerDiagnosticOutputStream << std::endl;

//	tokens = MyTokenizer::stringStreamCSV2(csvData);
//	for (auto s :  tokens) {
//		tokenizerDiagnosticOutputStream << s << " , ";
//	}
//	tokenizerDiagnosticOutputStream << std::endl;
//
//	tokens = MyTokenizer::stringStreamCSV3(csvData);
//	for (auto s :  tokens) {
//		tokenizerDiagnosticOutputStream << s << " , ";
//	}
//	tokenizerDiagnosticOutputStream << std::endl;

	/**
	 * use tokens to set Student attributes
	 * converting as required
	 */
	int id = 0;
	int age = 0;
#if defined(_WIN32)
	try {
	id = atoi( tokens[0] );
	} catch (std::exception& e) {
		std::cerr << "INVALID STRING REPRESENTATION '" << tokens[0] << std::endl;
		std::cerr << e.what() << std::endl;
	}
	int id = 0;
	int age = 0;
	try {
	age = atoi(  tokens[1] );
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
		age = stoi( tokens[1] );
	} catch (std::exception& e) {
		std::cerr << "INVALID STRING REPRESENTATION '" << tokens[1] << std::endl;
		std::cerr << e.what() << std::endl;
	}

	//	double gpa  = stod( tokens[5] );
#endif  // WIN32
	this->setId(id);
	this->setAge(age);
	this->setFirstName(tokens[2]);
	this->setLastName(tokens[3]);

	return tokenizerDiagnosticOutputStream;
}

int Person::getId() const {
	return id;
}
void Person::setId(int id) {
	this->id = id;
}

int Person::getAge() const {
	return age;
}
void Person::setAge(int age) {
	this->age = age;
}

const std::string& Person::getFirstName() const {
	return firstName;
}
void Person::setFirstName(const std::string &firstName) {
	this->firstName = firstName;
}

const std::string& Person::getLastName() const {
	return lastName;
}
void Person::setLastName(const std::string &lastName) {
	this->lastName = lastName;
}

const std::string Person::toString() const {
	std::stringstream ss;

	ss << "#" << this->getId();
	ss << " " << this->getFirstName();
	ss << " " << this->getLastName();
	ss << ", " << this->getAge();

	return ss.str();
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

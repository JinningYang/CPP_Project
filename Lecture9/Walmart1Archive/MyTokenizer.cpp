/*
 * MyTokenizer.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#include <iostream>			// std::cout, std::endl, std::cerr
#include <exception>		// std::exception
#include "MyTokenizer.h"

namespace edu {
namespace neu {
namespace csye6205 {

MyTokenizer::MyTokenizer() {
}

MyTokenizer::~MyTokenizer() {
}
/**
 * tokenizeCSV
 * parse tokens from CSV string to initialize attributes of Student object.
 *
 * "lastName,firstName,ID,studentId,age,gpa"
 */
std::vector<std::string> MyTokenizer::tokenizeCSV(std::string csvData, int ntokens) {
	int ix = ntokens;
	std::vector<std::string> tokens;
	const char  *delimiter = ",";		// constant

	std::cout << "tokenize using strtok: " << csvData << std::endl;

	/*
	 * convert std::string into a C language string
	 * using a vector of characters,
	 * with an added '\0' as a null termination for an end of string array.
	 */
	std::vector<char> csvString(std::begin(csvData), std::end(csvData));
//	std::vector<char> cString(csvData.begin(), csvData.end());
	csvString.push_back('\0');  // null terminate

	/**
	 * Use '\0' terminated contiguous data array,
	 * (the backing storage for vector container)
	 * as C language string for parsing 6 tokens.
	 */
	std::string str = NULL;
	try {
		str = strtok(csvString.data(), delimiter);
		ix--;	// decrement token index
		tokens.push_back( str );
//		tokens.push_back( strtok(csvString.data(), delimiter) );
	} catch (std::exception& e) {
		std::cerr << " ** STRTOK ERROR ** '" << str << "'" << ( ntokens - ix) << " of [" << ntokens << "] tokens" << std::endl;
		std::cerr << "INVALID STRING REPRESENTATION '" << csvData << "'" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	for (int i=1; i < ntokens; i++, --ix) {
		try {
			str = strtok(NULL, delimiter);
			tokens.push_back( str );
//			tokens.push_back( strtok(NULL, delimiter) );
		} catch (std::exception& e) {
		std::cerr << " ** STRTOK ERROR ** '" << str << "'" << ( ntokens - ix) << " of [" << ntokens << "] tokens" << std::endl;
		std::cerr << "INVALID STRING REPRESENTATION '" << csvData << "'" << std::endl;
		std::cerr << e.what() << std::endl;
		}
	}

	return tokens;
}
/**
 * stringStreamCSV1
 * parse tokens from CSV string to initialize attributes of Student object.
 */
std::vector<std::string> MyTokenizer::stringStreamCSV1(std::string csvData) {
	/*
	 * token delimiter char
	 */
	const char  delimiter = ',';
	/*
	 * token strings
	 */
	std::vector<std::string> tokens;
	std::string token;
	/*
	 * convert std::string to std::stringstream
	 */
	std::stringstream ss(csvData);

	std::cout << "tokenize using stringStreamCSV1: " << csvData << std::endl;
	while ( std::getline(ss, token, delimiter) ) {
		tokens.push_back(token);
	}

	return tokens;
}

/**
 * stringStreamCSV2
 * parse tokens from CSV string to initialize attributes of Student object.
 *
 * NOTE: NO SPACES ALLOWED IN CSV STRING
 */
std::vector<std::string> MyTokenizer::stringStreamCSV2(std::string csvData) {
	std::vector<std::string> tokens;
	char delimiterOld = ',';
	char delimiterNew = ' ';
	std::replace(csvData.begin(), csvData.end(), delimiterOld, delimiterNew);
	std::stringstream ss(csvData);
	std::string token;

	std::cout << "tokenize using stringStreamCSV2: " << csvData << std::endl;

	while ( std::getline(ss, token, delimiterNew) ) {
		tokens.push_back(token);
	}

	return tokens;
}

/**
 * stringStreamCSV3
 * parse tokens from CSV string to initialize attributes of Student object.
 *
 * NOTE: NO SPACES ALLOWED IN CSV STRING
 */
std::vector<std::string> MyTokenizer::stringStreamCSV3(std::string csvData) {
	std::vector<std::string> tokens;
	const char delimiterOld = ',';
	const char delimiterNew = ' ';
	std::replace(csvData.begin(), csvData.end(), delimiterOld, delimiterNew);
	std::stringstream ss(csvData);
	std::string token;

	std::cout << "tokenize using stringStreamCSV3: " << csvData << std::endl;

	for( std::string token; ss >> token; ) {
		tokens.push_back(token);
	}

	return tokens;
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

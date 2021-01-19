/*
 * MyTokenizer.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef MYTOKENIZER_H_
#define MYTOKENIZER_H_

#include <sstream>		// std::stringstream
#include <vector>		// std::vector

namespace edu {
namespace neu {
namespace csye6205 {

class MyTokenizer {
public:
	MyTokenizer();
	virtual ~MyTokenizer();

	/**
	 * tokenizeCSV
	 * parse tokens from CSV string to initialize attributes of Student object.
	 *
	 * "lastName,firstName,ID,studentId,age,gpa"
	 */
	static std::vector<std::string> tokenizeCSV(std::string csvData, int ntokens);
	/**
	 * stringStreamCSV1
	 * parse tokens from CSV string to initialize attributes of Student object.
	 */
	static std::vector<std::string> stringStreamCSV1(std::string csvData);
	/**
	 * stringStreamCSV2
	 * parse tokens from CSV string to initialize attributes of Student object.
	 */
	static std::vector<std::string> stringStreamCSV2(std::string csvData);

	/**
	 * stringStreamCSV3
	 * parse tokens from CSV string to initialize attributes of Student object.
	 */
	static std::vector<std::string> stringStreamCSV3(std::string csvData);
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* MYTOKENIZER_H_ */

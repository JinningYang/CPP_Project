#ifndef ABSTRACTPERSONAPI_H_
#define ABSTRACTPERSONAPI_H_

#include <string>				// std::string
#include <memory>

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractPersonAPI;
class Item;

typedef bool (*CompareAbstractPersonPtrs_t)(std::unique_ptr<AbstractPersonAPI> &, std::unique_ptr<AbstractPersonAPI> &);

class AbstractPersonAPI {
public:
	AbstractPersonAPI();
	virtual ~AbstractPersonAPI();

	virtual int getAge() const = 0;
	virtual void setAge(int age) = 0;
	virtual const std::string& getFirstName() const = 0;
	virtual void setFirstName(const std::string &firstName) = 0;
	virtual int getId() const = 0;
	virtual void setId(int id) = 0;
	virtual const std::string& getLastName() const = 0;
	virtual void setLastName(const std::string &lastName) = 0;

	virtual std::string info()=0;

	static bool comparePersonID(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2);
	static bool comparePersonAge(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2);
	static bool comparePersonFirstName(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2);
	static bool comparePersonLastName(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2);
};

/**
 * Comparators
 */
bool comparePersonID(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2);
bool comparePersonAge(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2);
bool comparePersonFirstName(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2);
bool comparePersonLastName(std::unique_ptr<AbstractPersonAPI> &p1, std::unique_ptr<AbstractPersonAPI> &p2);

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* ABSTRACTPERSONAPI_H_ */

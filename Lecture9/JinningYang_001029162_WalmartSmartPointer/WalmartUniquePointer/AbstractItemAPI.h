#ifndef ABSTRACTITEMAPI_H_INCLUDED
#define ABSTRACTITEMAPI_H_INCLUDED

#include <string>				// std::string
#include <memory>

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractItemAPI;

typedef bool (*CompareItemPtrs_t)(std::unique_ptr<AbstractItemAPI>&, std::unique_ptr<AbstractItemAPI>&);

/**
 * AbstractItemAPI for each Item object
 */
class AbstractItemAPI {
public:
	AbstractItemAPI();
	virtual ~AbstractItemAPI();
    virtual std::string info() const = 0;
	virtual int getId() const = 0;
	virtual void setId(int id) = 0;

	virtual const std::string& getName() const = 0;
	virtual void setName(const std::string &name) = 0;

	virtual double getPrice() const = 0;
	virtual void setPrice(double price) = 0;

	static bool compareItemID(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2);
	static bool compareItemPrice(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2);
	static bool compareItemName(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2);
};

/**
 * Comparators
 */
bool compareItemID(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2);
bool compareItemPrice(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2);
bool compareItemName(std::unique_ptr<AbstractItemAPI> &p1, std::unique_ptr<AbstractItemAPI> &p2);

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */


#endif // ABSTRACTITEMAPI_H_INCLUDED

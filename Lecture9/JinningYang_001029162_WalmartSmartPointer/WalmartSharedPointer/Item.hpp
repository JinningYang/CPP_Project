#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED

#include "AbstractItemAPI.h"
#include <string>

namespace edu {
namespace neu {
namespace csye6205 {
class Item : public AbstractItemAPI {
  std::string _name;
  double _price;
  int _id;

public:
  Item(const std::string name, const double price, const int id)
      : _name(name), _price(price), _id(id){};
  //const std::string name() const { return _name; }
  std::string info() const {
    return "Item #" + std::to_string(_id) + ": " + _name + ", $" +
           std::to_string(_price);
  }
  //double price() const {return _price;}
  //int id() const { return _id; }
    int getId() const {
        return _id;
    }

    void setId(int id){
        this->_id = id;
    }

	const std::string& getName() const{
        return _name;
	}
	void setName(const std::string &name){
        this->_name = name;
	}

	double getPrice() const{
        return _price;
	}
	void setPrice(double price){
        this->_price = price;
	}
};

} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // ITEM_HPP_INCLUDED

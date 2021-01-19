#ifndef WALMART_HPP_INCLUDED
#define WALMART_HPP_INCLUDED

#include "AbstractItemAPI.h"
#include "AbstractPersonAPI.h"
#include "AbstractStoreAPI.h"
#include "ItemFactory.hpp"
#include "PersonFactory.hpp"
#include "Store.hpp"

#include <cstring>

namespace edu {
namespace neu {
namespace csye6205 {

class Walmart : public Store {
public:
  static void demo() {
    std::cout << "\n\t"
              << "Walmart::demo() starting..." << std::endl;
    {
      Walmart walmart;

      walmart.addInventory(
          std::move(ItemFactory::getItem("Wonder bread", 1.49, 2, ItemFactory::ITEM)));
      walmart.addInventory(
          std::move(ItemFactory::getItem("Tropicana OJ", 3.49, 4, ItemFactory::ITEM)));
      walmart.addInventory(
          std::move(ItemFactory::getItem("Hood 2% Milk", 2.49, 3, ItemFactory::ITEM)));
      walmart.addInventory(
              std::move(ItemFactory::getItem("Golden apples", 0.89, 5, ItemFactory::ITEM)));
      walmart.addInventory(
              std::move(ItemFactory::getItem("Apricots", 0.89, 6, ItemFactory::ITEM)));
      walmart.addEmployees(std::move(PersonFactory::getPerson("Dan", "Peters", 1001, 17,PersonFactory::PERSON)));
      walmart.addEmployees(std::move(PersonFactory::getPerson("Sam", "Sneed", 1003, 19,PersonFactory::PERSON)));
      walmart.addEmployees(std::move(PersonFactory::getPerson("Jane", "Eyre", 1002, 39,PersonFactory::PERSON)));

      std::cout << "\n\t"
                << "Sort employees by ID and inventory by item ID."
                << std::endl;
      walmart.sortEmployees(comparePersonID);
      walmart.sortInventory(compareItemID);
      walmart.show();
      std::cout << "\n\t"
                << "Sort employees by AGE and inventory by item PRICE."
                << std::endl;
      walmart.sortEmployees(comparePersonAge);
      walmart.sortInventory(compareItemPrice);
      walmart.show();
      std::cout << "\n\t"
                << "Sort employees by FIRST NAME and inventory by item NAME."
                << std::endl;
      walmart.sortEmployees(comparePersonFirstName);
      walmart.sortInventory(compareItemName);
      walmart.show();
      std::cout << "\n\t"
                << "Sort employees by LAST NAME and inventory by item NAME."
                << std::endl;
      walmart.sortEmployees(comparePersonLastName);
      walmart.sortInventory(compareItemName);
      walmart.show();
    }
  };
};
} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // WALMART_HPP_INCLUDED

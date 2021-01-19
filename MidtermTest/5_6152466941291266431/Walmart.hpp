#pragma once

#include "AbstractItemAPI.h"
#include "AbstractPersonAPI.h"
#include "AbstractStoreAPI.h"
#include "ItemFactory.hpp"
#include "Person.hpp"
#include "Store.hpp"

#include <cstring>

namespace edu {
namespace neu {
namespace csye6205 {

class Walmart : public Store {
public:
  static void demo() {

    AbstractStoreAPI::CompareAbstractPersonPtrs_t compareEmployeeIDFunction =
        [](auto *p1, auto *p2) { return p1->id() < p2->id(); };

    AbstractStoreAPI::CompareAbstractPersonPtrs_t compareEmployeeAgeFunction =
        [](auto p1, auto p2) { return p1->age() < p2->age(); };

    AbstractStoreAPI::CompareItemPtrs_t compareItemIDFunction =
        [](auto *i1, auto *i2) { return i1->id() < i2->id(); };

    AbstractStoreAPI::CompareItemPtrs_t compareItemPriceFunction =
        [](auto i1, auto i2) { return i1->price() < i2->price(); };

    AbstractStoreAPI::CompareAbstractPersonPtrs_t
        compareEmployeeFirstNameFunction = [](auto p1, auto p2) {
          return std::strcmp(p1->firstName().c_str(), p2->firstName().c_str()) < 0;
        };

    AbstractStoreAPI::CompareAbstractPersonPtrs_t
        compareEmployeeLastNameFunction = [](auto p1, auto p2) {
          return std::strcmp(p1->lastName().c_str(), p2->lastName().c_str()) < 0;
        };

    AbstractStoreAPI::CompareItemPtrs_t compareItemNameFunction = [](auto i1,
                                                                     auto i2) {
      return std::strcmp(i1->name().c_str(), i2->name().c_str()) < 0;
    };

    std::cout << "\n\t"
              << "Walmart::demo() starting..." << std::endl;
    {
      Walmart walmart;

      walmart.addInventory(
          ItemFactory::getItem("Wonder bread", 1.49, 2, ItemFactory::BREAD));
      walmart.addInventory(
          ItemFactory::getItem("Tropicana OJ", 3.49, 4, ItemFactory::ITEM));
      walmart.addInventory(
          ItemFactory::getItem("Hood 2% Milk", 2.49, 3, ItemFactory::ITEM));
      walmart.addInventory(
          ItemFactory::getItem("Golden apples", 0.89, 5, ItemFactory::ITEM));
      walmart.addInventory(
          ItemFactory::getItem("Apricots", 0.89, 6, ItemFactory::ITEM));
      walmart.addEmployees(new Person("Dan", "Peters", 1001, 17));
      walmart.addEmployees(new Person("Sam", "Sneed", 1003, 19));
      walmart.addEmployees(new Person("Jane", "Eyre", 1002, 39));

      std::cout << "\n\t"
                << "Sort employees by ID and inventory by item ID."
                << std::endl;
      walmart.sortEmployees(compareEmployeeIDFunction);
      walmart.sortInventory(compareItemIDFunction);
      walmart.show();
      std::cout << "\n\t"
                << "Sort employees by AGE and inventory by item PRICE."
                << std::endl;
      walmart.sortEmployees(compareEmployeeAgeFunction);
      walmart.sortInventory(compareItemPriceFunction);
      walmart.show();
      std::cout << "\n\t"
                << "Sort employees by FIRST NAME and inventory by item NAME."
                << std::endl;
      walmart.sortEmployees(compareEmployeeFirstNameFunction);
      walmart.sortInventory(compareItemNameFunction);
      walmart.show();
      std::cout << "\n\t"
                << "Sort employees by LAST NAME and inventory by item NAME."
                << std::endl;
      walmart.sortEmployees(compareEmployeeLastNameFunction);
      walmart.sortInventory(compareItemNameFunction);
      walmart.show();
    }
  };
};
} // namespace csye6205
} // namespace neu
} // namespace edu
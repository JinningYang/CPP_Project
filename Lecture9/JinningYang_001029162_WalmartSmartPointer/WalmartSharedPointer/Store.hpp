#ifndef STORE_HPP_INCLUDED
#define STORE_HPP_INCLUDED

#pragma once

#include "AbstractItemAPI.h"
#include "AbstractPersonAPI.h"
#include "AbstractStoreAPI.h"
#include <algorithm>
#include <iostream>
#include <vector>

namespace edu {
namespace neu {
namespace csye6205 {

class Store : public AbstractStoreAPI {
public:
  ~Store() {
    clearInventory();
    employees.clear();
  }
  void show() {
    std::cout << "Store " << name << " (#" << id << "):\n";
    std::cout << "\tEmployees:\n";
    std::cout << getEmployeeInfo();
    std::cout << "\tInventory:\n";
    showInventory();
  }
  void clearInventory() {
    inventory.clear();
  }
  void showInventory() { std::cout << getInventoryInfo(); }
  int getId() const { return id; }
  void setId(int id) { this->id = id; }
  const std::string &getName() const { return name; };
  void setName(const std::string &name) { this->name = name; }
  void addEmployees(std::shared_ptr<AbstractPersonAPI> p) { employees.emplace_back(p); }
  void addInventory(std::shared_ptr<AbstractItemAPI> e) { inventory.emplace_back(e); }
  void sortInventory(CompareItemPtrs_t c) {
     std::sort(inventory.begin(), inventory.end(), c);
  }
  void sortEmployees(CompareAbstractPersonPtrs_t c) {
    std::sort(employees.begin(), employees.end(), c);
  }
  std::string getInventoryInfo() {
    std::string ret;
    for (auto &it : inventory) {
      auto i = it->info();
      ret += "\t\t" + i + '\n';
    }
    return ret;
  }

  std::string getEmployeeInfo() {
    std::string ret;
    for (auto &it : employees) {
      auto i = it->info();
      ret += "\t\t" + i + '\n';
    }
    return ret;
  }

private:
  int id;
  std::string name;
  std::vector<std::shared_ptr<AbstractPersonAPI>> employees;
  std::vector<std::shared_ptr<AbstractItemAPI>> inventory;
};
} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // STORE_HPP_INCLUDED

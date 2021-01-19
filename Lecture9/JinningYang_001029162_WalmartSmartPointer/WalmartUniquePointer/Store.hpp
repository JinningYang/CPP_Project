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
  void show() override {
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
  int getId() const override { return id; }
  void setId(int id) override { this->id = id; }
  const std::string &getName() const override { return name; };
  void setName(const std::string &name) override { this->name = name; }
  void addEmployees(std::unique_ptr<AbstractPersonAPI>&& p) override { employees.emplace_back(std::move(p)); }
  void addInventory(std::unique_ptr<AbstractItemAPI>&& e) override { inventory.emplace_back(std::move(e)); }
  void sortInventory(CompareItemPtrs_t c) override {
     std::sort(inventory.begin(), inventory.end(), c);
  }
  void sortEmployees(CompareAbstractPersonPtrs_t c) override {
    std::sort(employees.begin(), employees.end(), c);
  }
  std::string getInventoryInfo() override {
    std::string ret;
    for (auto &it : inventory) {
      auto i = it->info();
      ret += "\t\t" + i + '\n';
    }
    return ret;
  }

  std::string getEmployeeInfo() override {
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
  std::vector<std::unique_ptr<AbstractPersonAPI>> employees;
  std::vector<std::unique_ptr<AbstractItemAPI>> inventory;
};
} // namespace csye6205
} // namespace neu
} // namespace edu

#endif // STORE_HPP_INCLUDED

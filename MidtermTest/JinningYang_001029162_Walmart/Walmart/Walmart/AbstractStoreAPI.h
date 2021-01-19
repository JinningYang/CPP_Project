#ifndef HEADER_C092F5EE1B330B64
#define HEADER_C092F5EE1B330B64

/*
 * AbstractStoreAPI.h
 *
 *  Created on: Nov 10, 2020
 *      Author: dgpeters
 */

#ifndef ABSTRACTSTOREAPI_H_
#define ABSTRACTSTOREAPI_H_

#include "AbstractItemAPI.h"
#include "AbstractPersonAPI.h"
#include <string> // std::string

namespace edu {
namespace neu {
namespace csye6205 {

class AbstractStoreAPI {
public:
  AbstractStoreAPI(){}
  virtual ~AbstractStoreAPI(){}
  template <typename T>
  using Compare_t = std::function<bool(const T *, const T *)>;
  using CompareItemPtrs_t = Compare_t<AbstractItemAPI>;
  using CompareAbstractPersonPtrs_t = Compare_t<AbstractPersonAPI>;
  virtual void show() = 0;
  virtual void clearInventory() = 0;
  virtual void showInventory() = 0;
  virtual int getId() const = 0;
  virtual void setId(int id) = 0;
  virtual const std::string &getName() const = 0;
  virtual void setName(const std::string &name) = 0;
  virtual void addEmployees(AbstractPersonAPI *p) = 0;
  virtual void addInventory(AbstractItemAPI *e) = 0;
  virtual void sortInventory(CompareItemPtrs_t c) = 0;
  virtual void sortEmployees(CompareAbstractPersonPtrs_t c) = 0;
  virtual std::string getInventoryInfo() = 0;
  virtual std::string getEmployeeInfo() = 0;
};

} // namespace csye6205
} // namespace neu
} // namespace edu
#endif /* ABSTRACTSTOREAPI_H_ */

#endif // header guard 


/*
 * Inventory.h
 *
 *  Created on: Nov 17, 2020
 *      Author: dgpeters
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <iostream>				// std::cout, std::endl, std::cerr
#include <string>				// std::string
#include <map>					// std::map

namespace edu {
namespace neu {
namespace csye6205 {

struct Part {
	std::string_view _name;
	bool _isAvailable { false } ;
};
typedef std::map<int, Part> PartMap_t;

class Inventory {
	private:
	std::map<int, Part> _parts;
//	std::string_view nameTarget = nullptr;
//	Part* FindByNameImpl(std::string_view name) {
//		this->nameTarget  = name;
//		auto it = std::find_if(std::begin(this->_parts),
//								std::end(this->_parts),
//								Inventory::isANameMatchStatic);
//
////		auto it = std::find_if(std::begin(this->_parts),
////								std::end(this->_parts),
////								[&name](const PartMap_t & entry) {
////			return entry.second._name == name;
////		});
//		if (it != _parts.end()) {
//			return &it->second;
//		}
//		return nullptr;
//	}
public:
	Inventory();
	Inventory(const PartMap_t parts);
	virtual ~Inventory();

//	static bool isANameMatchStatic(const PartMap_t & entry) {
//		Inventory obj;
//		return obj.isANameMatch(entry);
//	}
//
//	bool isANameMatch(const std::map<int, Part> & entry) {
//			return false;
////			return entry.second._name == this->nameTarget;
//	}
//	bool Contains(std::string_view name) {
//		return FindByNameImpl(name) != nullptr;
//	}
//	void SetAvailability(std::string_view name, bool isAvailable) {
//		auto pPart = FindByNameImpl(name);
//		if (pPart) {
//			pPart->_isAvailable = isAvailable;
//		}
//	}
};

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

#endif /* INVENTORY_H_ */

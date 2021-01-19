/*
 * Inventory.cpp
 *
 *  Created on: Nov 17, 2020
 *      Author: dgpeters
 */

#include "Inventory.h"

namespace edu {
namespace neu {
namespace csye6205 {

Inventory::Inventory() {
}
Inventory::Inventory(PartMap_t parts) : _parts(parts) {
}

Inventory::~Inventory() {
}

} /* namespace csye6205 */
} /* namespace neu */
} /* namespace edu */

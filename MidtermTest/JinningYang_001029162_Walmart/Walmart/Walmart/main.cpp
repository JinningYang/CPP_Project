#include <iostream>
#include "Walmart.hpp"
using namespace std;

int main()
{
    edu::neu::csye6205::Walmart::demo();
    return 0;
}
//Walmart::demo() starting...

//        Sort employees by ID and inventory by item ID.
//Store  (#7470348):
//        Employees:
//                Person #1001: Dan Peters, age 17
//                Person #1002: Jane Eyre, age 39
//                Person #1003: Sam Sneed, age 19
//        Inventory:
//                Item #2: Wonder bread, $1.490000, calories: 0
//                Item #3: Hood 2% Milk, $2.490000
//                Item #4: Tropicana OJ, $3.490000
//                Item #5: Golden apples, $0.890000
//                Item #6: Apricots, $0.890000
//
//        Sort employees by AGE and inventory by item PRICE.
//Store  (#7470348):
//        Employees:
//                Person #1001: Dan Peters, age 17
//                Person #1003: Sam Sneed, age 19
//                Person #1002: Jane Eyre, age 39
//        Inventory:
//                Item #5: Golden apples, $0.890000
//                Item #6: Apricots, $0.890000
//                Item #2: Wonder bread, $1.490000, calories: 0
//                Item #3: Hood 2% Milk, $2.490000
//                Item #4: Tropicana OJ, $3.490000

//        Sort employees by FIRST NAME and inventory by item NAME.
//Store  (#7470348):
//        Employees:
//                Person #1001: Dan Peters, age 17
//                Person #1002: Jane Eyre, age 39
//                Person #1003: Sam Sneed, age 19
//        Inventory:
//                Item #6: Apricots, $0.890000
//                Item #5: Golden apples, $0.890000
//                Item #3: Hood 2% Milk, $2.490000
//                Item #4: Tropicana OJ, $3.490000
//                Item #2: Wonder bread, $1.490000, calories: 0
//
//        Sort employees by LAST NAME and inventory by item NAME.
//Store  (#7470348):
//        Employees:
//                Person #1002: Jane Eyre, age 39
//                Person #1001: Dan Peters, age 17
//                Person #1003: Sam Sneed, age 19
//        Inventory:
//                Item #6: Apricots, $0.890000
//                Item #5: Golden apples, $0.890000
//                Item #3: Hood 2% Milk, $2.490000
//                Item #4: Tropicana OJ, $3.490000
//                Item #2: Wonder bread, $1.490000, calories: 0

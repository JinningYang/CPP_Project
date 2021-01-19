#include <iostream>
#include "queue.hpp"
#include "stack.hpp"
#include "stacktemplate.hpp"
#include "queuetemplate.hpp"
using namespace std;

int main()
{
    edu::neu::csye6205::queue::demo();
    edu::neu::csye6205::stack::demo();
    edu::neu::csye6205::stacktemplate<string>::demo();
    edu::neu::csye6205::queuetemplate<string>::demo();
    return 0;
}
//       Queue::demo() start!
//Inserting 1
//Inserting 2
//Inserting 3
//Front element is: 1
//Removing 1
//Front element is: 2
//Queue size is 2
//Removing 2
//Removing 3
//Queue Is Empty
//
//        Queue::demo() end!
//
//        Stack::demo() start!
//Inserting 1
//Inserting 2
//Removing 2
//Removing 1
//Inserting 3
//Top element is: 3
//Stack size is 1
//Removing 3
//Stack Is Empty
//
//        Stack::demo() end!
//Stack Template::demo() start!
//Inserting C
//Inserting S
//Removing S
//Removing C
//Inserting Y
//Top element is: Y
//Stack size is 1
//Removing Y
//Stack Is Empty
//
//        Stack Template::demo() end!
//
//        Queue Template::demo() start!
//Inserting C
//Inserting S
//Inserting Y
//Front element is: C
//Removing C
//Inserting E
//Queue size is 3
//Removing S
//Removing Y
//Removing E
//Queue Is Empty
//
//      Queue Template::demo() end!

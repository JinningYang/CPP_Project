#ifndef STACKTEMPLATE_HPP_INCLUDED
#define STACKTEMPLATE_HPP_INCLUDED

#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

namespace edu{
namespace neu{
namespace csye6205{
template <class X>
class stacktemplate{
    X *arr;
    int top;
    int capacity;

public:
    stacktemplate(int size = SIZE);
    void push(X);
    X pop();
    X peek();

    int size();
    bool isEmpty();
    bool isFull();

    ~stacktemplate(){
        delete[] arr;
    }
    static void demo();
};

template <class X>
stacktemplate<X>::stacktemplate(int size){
    arr = new X[size];
    capacity = size;
    top = -1;
}

template <class X>
void stacktemplate<X>::push(X x) {
    if (isFull()){
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

template <class X>
X stacktemplate<X>::pop(){
    if (isEmpty()){
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    return arr[top--];
}

template <class X>
X stacktemplate<X>::peek(){
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

template <class X>
int stacktemplate<X>::size(){
    return top + 1;
}

template <class X>
bool stacktemplate<X>::isEmpty(){
    return top == -1;
}

template <class X>
bool stacktemplate<X>::isFull(){
    return top == capacity - 1;
}

template <class X>
void stacktemplate<X>::demo(){
    std::cout << "\n\t"
              << "Stack Template::demo() start!" << std::endl;
    stacktemplate<string> pt(2);

    pt.push("C");
    pt.push("S");

    pt.pop();
    pt.pop();

    pt.push("Y");

    cout << "Top element is: " << pt.peek() << endl;

    cout << "Stack size is " << pt.size() << endl;

    pt.pop();

    if (pt.isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack Is Not Empty\n";

    std::cout << "\n\t"
              << "Stack Template::demo() end!" << std::endl;

}

}
}
}

#endif // STACKTEMPLATE_HPP_INCLUDED

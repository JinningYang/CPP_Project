#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 3

namespace edu{
namespace neu{
namespace csye6205{
class stack{
    int *arr;
    int top;
    int capacity;

public:
    stack(int size = SIZE);
    ~stack();

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
    static void demo();
};

stack::stack(int size){
    arr = new int[size];
    capacity = size;
    top = -1;
}

stack::~stack(){
    delete[] arr;
}

void stack::push(int x){
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

int stack::pop(){
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;
    return arr[top--];
}

int stack::peek(){
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

int stack::size(){
    return top + 1;
}

bool stack::isEmpty(){
    return top == -1;
}

bool stack::isFull(){
    return top == capacity - 1;
}

void stack::demo(){
    std::cout << "\n\t"
              << "Stack::demo() start!" << std::endl;
    stack pt(3);

    pt.push(1);
    pt.push(2);

    pt.pop();
    pt.pop();

    pt.push(3);

    cout << "Top element is: " << pt.peek() << endl;
    cout << "Stack size is " << pt.size() << endl;

    pt.pop();

    if (pt.isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack Is Not Empty\n";

    std::cout << "\n\t"
              << "Stack::demo() end!" << std::endl;
}

}
}
}

#endif // STACK_HPP_INCLUDED

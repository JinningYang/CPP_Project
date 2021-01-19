#ifndef QUEUETEMPLATE_HPP_INCLUDED
#define QUEUETEMPLATE_HPP_INCLUDED

#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

namespace edu{
namespace neu{
namespace csye6205{
template <class X>
class queuetemplate{
    X *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    queuetemplate(int size = SIZE);

    void dequeue();
    void enqueue(X x);
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
    static void demo();
};

template <class X>
queuetemplate<X>::queuetemplate(int size){
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

template <class X>
void queuetemplate<X>::dequeue(){

    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
}

template <class X>
void queuetemplate<X>::enqueue(X item)
{

    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

template <class X>
X queuetemplate<X>::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

template <class X>
int queuetemplate<X>::size()
{
    return count;
}

template <class X>
bool queuetemplate<X>::isEmpty()
{
    return (size() == 0);
}

template <class X>
bool queuetemplate<X>::isFull()
{
    return (size() == capacity);
}

template <class X>
void queuetemplate<X>::demo(){
    std::cout << "\n\t"
              << "Queue Template::demo() start!" << std::endl;
    queuetemplate<string> q(4);

    q.enqueue("C");
    q.enqueue("S");
    q.enqueue("Y");

    cout << "Front element is: " << q.peek() << endl;
    q.dequeue();

    q.enqueue("E");

    cout << "Queue size is " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.isEmpty())
        cout << "Queue Is Empty\n";
    else
        cout << "Queue Is Not Empty\n";

    std::cout << "\n\t"
              << "Queue Template::demo() end!" << std::endl;

}

}
}
}

#endif // QUEUETEMPLATE_HPP_INCLUDED

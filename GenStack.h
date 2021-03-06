#include <iostream>

using namespace std;

template <class T>
class GenStack
{
  public:
    GenStack();//constructor
    GenStack(int maxSize);//overloaded constructor
    ~GenStack();//destructor

    int push(T d);
    T pop();
    T peek();//aka top()

    int getSize();
    bool isEmpty();
    bool isFull();

    int size;
    int top;

    T *myArray;
    T *doubleArray;
};

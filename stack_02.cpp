#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int Size;
    int top;

public:
    Stack(int size)
    {
        Size = size;
        arr = new int[Size];
        top = 0 ;
    }

    void push(int x){
        if(top==Size){
            cout << "Stack Overflow"<<"\n";
            return;
        }
        arr[++top]=x;
    }


};
int main()
{
    Stack(4);
    return 0;
}
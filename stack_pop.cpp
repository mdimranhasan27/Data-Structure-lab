#include<iostream>
using namespace std ;
class Stack{
    int *arr;
    int Size;
    int top;

    public :
    
    Stack(int size)
    {
        Size = size;
        arr = new int[Size];
        top = -1 ;
    }
    int pop() {
        if (top == -1) {
            cout << "  Stack Underflow ";
            return -1;
        }
        return arr[top--];
    }

};
int main(){
    Stack st(4);
    cout<<"Popped"<<st.pop();
    return 0;
}
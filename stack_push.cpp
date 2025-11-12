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
        top = -1 ;
    }

    void push(int x){
        if(top==Size-1){
            cout << "Stack Overflow"<<"\n";
            return;
        }
        arr[++top]=x;
    }
    void print(){
        for(int i=0;i<top+1;i++){
            cout << arr[i] << " ";
        }
        cout<< "\n";
    }
    int Top(){
        return top+1;
    }


};
int main()
{
    Stack st(4);

    st.push(1);
    st.push(2);
    st.push(5);
    st.push(7);
    st.print();
    int top=st.Top();
        cout<<"TOP element in indexes: "<<top<<"\n";
    
    return 0;
}
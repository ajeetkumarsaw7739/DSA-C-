#include<iostream>
using namespace std;

class stack {
    public:
    int *arr;
    int size;
    int top;

    //constructor
    stack(int s){
        this->size = s;
        this->top = -1;
        arr = new int[size];
    }
    //push element
    void push(int x){

        if(size - top > 1){
        top++;
        arr[top] = x;
        }
        else{
            cout << "stack is overflow " << endl;
    
        }
    }   
    //pop element
    void pop(){

        if(top >= 0){
            top--;
        }
        else{
           cout << "stack is underflow " << endl;
        }
    }
    //stack ka top element
    int peek(){

        if(top >= 0){
            return arr[top];
        }
        else{
            cout << "stack is empty " << endl;
            return -1;
        }
    }
    //stack is empty or not
    bool isempty(){

        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){

    stack st(5);
    
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);

    cout << "top element:" << st.peek() << endl;

    st.pop();

    cout << "top element:" << st.peek() << endl;
    
    if(st.isempty()){
        cout << "stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }
    return 0;
}
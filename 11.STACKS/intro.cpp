#include<bits/stdc++.h>
using namespace std;

class Stack{

     public:
        int *arr;
        int top;
        int size;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;

    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }else{
             cout<<"Stack underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }else{
             cout<<"Stack empty"<<endl;
             return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};


int main()
{   
    Stack st(5);

    st.push(22);
    st.push(44);
    st.push(66);
    st.push(22);
    st.push(44);
    st.push(66);

    cout<<"Top Element: "<<st.peek()<<endl;

    st.pop();
    cout<<"Top Element: "<<st.peek()<<endl;

     st.pop();
    cout<<"Top Element: "<<st.peek()<<endl;

     st.pop();
    cout<<"Top Element: "<<st.peek()<<endl;

    if (st.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }


/*
 //using STL
    stack<int>s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.push(3);
    
     cout << "Top element: " << s.top() << endl;


     if (s.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    cout << "Size of stack is: " << s.size() << endl;
    */
   
    return 0;
}
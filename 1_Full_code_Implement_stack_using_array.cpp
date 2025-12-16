//full code for implementation of stack using array

#include<iostream>
using namespace std;
class Stack{
    public:
        int *arr;
        int top;
        int n;         //size

        Stack(int n){
            this->n=n;
            top=-1;
            arr=new int[n];
        }

        void push(int element){
            if(top<n-1){
                top++;
                arr[top]=element;
            }
            else{
                cout<<"stack overflow"<<endl;
            }
        }

        void pop(){
            if(top!=-1) top--;
            else cout<<"stack underflow"<<endl;
        }

        int peek(){
            if(top!=-1) return arr[top];
            cout<<"stack is empty"<<endl;
            return -1;
        }

        bool isempty(){
            if(top==-1) return true;
            return false;
        }
        //to remove memory leak - add destructor
        ~Stack(){
          delete[] arr;
        }

};

int main(){
    Stack st(5);
    st.push(4);
    st.push(3);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.isempty()<<endl;
    st.pop();
    st.pop();
    cout<<st.isempty()<<endl;
    cout<<st.peek()<<endl;

    return 0;
}

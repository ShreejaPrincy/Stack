//Implement stack using array
//GFG
//my_code

class myStack {
  public:
  
    int n;
    int *arr;
    int top;
    
    myStack(int n) {
        // Define Data Structures
        this->n=n;
        top=-1;
        arr=new int[n];
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top==-1) return true;
        else    return false;
    }

    bool isFull() {
        // check if the stack is full
        if(top==n-1)    return true;
        return false;
        
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(top<n){
            top++;
            arr[top]=x;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(top!=-1) top--;
    }

    int peek() {
        // Returns the top element of the stack
        if(top!=-1) return arr[top];
        return -1;
    }
};

//my code
//doitagin
//tc and sc = O(1)
class MinStack {
    stack<long long>st;
    long long mini;
public:
    MinStack() {
        this->mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()||1LL*val>=mini){            //=
            if(st.empty())  mini=1LL*val;          
            st.push(1LL*val);
            return;
        }
        long long value=1LL*2*val-mini;
        st.push(value);
        mini=1LL*val;
    }
    
    void pop() {
        if(st.empty())  return;
        if(st.top()>=mini)   st.pop();
        else{
            long long value=2*mini-st.top();
            mini=value;
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())  return -1;
        if(st.top()>=mini)    return (int)st.top();
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};


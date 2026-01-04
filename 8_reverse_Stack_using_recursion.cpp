//my code
// We remove elements one by one and reinsert them at the bottom while backtracking.
// T.C - O(n^2)
// S.C - O(n)
void insertAtbottom(stack<int>&st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int t=st.top();
    st.pop();
    insertAtbottom(st,x);
    st.push(t);
}
void solve(stack<int>&st){
    if(st.size()==1)  return;

    int x=st.top();
    st.pop();
    solve(st);
    insertAtbottom(st,x);
}
void reverseStack(stack<int> &stack){
    solve(stack);
}

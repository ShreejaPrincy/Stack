//T.C - O(n)
//S.C - O(n) because of stack

string rev(string str){
  stack<char> st;
  for(int i=0;i<str.size();i++){
    st.push(str[i]);
  }
  int i=0;
  while(!st.empty()){
    char c=st.top();
    str[i++]=c;
    st.pop();
  }
  return str;
}

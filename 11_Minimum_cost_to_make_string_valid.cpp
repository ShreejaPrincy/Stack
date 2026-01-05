//APPROACH - 1

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  stack<char>st;
  if(str.size()%2!=0) return -1;

  for(int i=0;i<str.size();i++){
    if(!st.empty()&&str[i]=='}'&&st.top()=='{') st.pop();
    else  st.push(str[i]);
  }

  int a=0,b=0;
  while(!st.empty()){
    
    if(st.top()=='{') a++;
    else  b++;
    
    st.pop();                      //*
  }
  
  return (a+1)/2 +(b+1)/2;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// APPROACH - 2 
//(my)

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  stack<char>st;
  for(int i=0;i<str.size();i++){
    if(!st.empty()&&str[i]=='}'&&st.top()=='{') st.pop();
    else  st.push(str[i]);
  }
  int cnt=0;
  while(!st.empty()){
    char c=st.top();
    st.pop();
    if(st.empty()) return -1;
    else if(c==st.top()){
      cnt++;
      st.pop();
    }
    else if(st.top()!=c){
      cnt+=2;
      st.pop();
    }
  }
  return cnt;
}




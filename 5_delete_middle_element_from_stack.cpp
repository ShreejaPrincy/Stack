// Where I got stuck:
// The issue was using `mid--` inside the recursive function call.
//
// Why `mid--` is a problem:
// `mid--` is a post-decrement operator, so it works in two steps:
// 1. The current value of `mid` is passed to the function.
// 2. Then `mid` is decremented, but only in the current stack frame.
//
// As a result, the recursive call receives the old value of `mid`,
// not the decremented one.
//
// This causes recursion like:
// solve(st, 3)
//   → solve(st, 3)
//     → solve(st, 3)
//       → solve(st, 3)
//
// The base condition (mid == 1) is never reached.

#include <bits/stdc++.h> 
void solve(stack<int>&st,int mid){
   if(mid==1){
      st.pop();
      return;
   }
   int x=0;
   x=st.top();
   st.pop();
   solve(st,mid-1);     //do not use m--
   st.push(x);
   return;
}
void deleteMiddle(stack<int>&inputStack, int N){
   int mid=N/2+1;
   solve(inputStack,mid);
}

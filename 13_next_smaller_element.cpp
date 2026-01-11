//understant the question and examples properly
//The Next Smaller Element (NSE) of an element x is the first element that appears to the right of x in the array and is strictly smaller than x

//eg
//arr = [5, 3, 4, 2]
//output - [3, 2, 2, -1]
//explaination - 🔹 5
//                Right side: 3 4 2
//                3 < 5 → ✅ stop immediately
//                Answer = 3

//t.c - O(n)
//s.c - O(n)
//my code

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        stack<int>st;
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            int curr=arr[i];
            if(st.top()>=curr){
                while(st.top()>=curr)   st.pop();
            }
            arr[i]=st.top();
            st.push(curr);
        }
        return arr;
    }
};

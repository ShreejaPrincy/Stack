// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
  public:
    string preToInfix(string s) {
        stack<string>st;
        for(int i=s.size()-1;i>=0;i--){
            char ch =s[i];
            if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
                st.push(string(1,ch));
            else{
                string op1=st.top();
                st.pop();
                
                string op2=st.top();
                st.pop();
                
                string s="("+op1+ch+op2+")";
                st.push(s);
            }
        }
        return st.top();
    }
};

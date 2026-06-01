// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
  public:
    int prec(char ch) {
        if(ch == '+' || ch == '-') return 1;
        if(ch == '/' || ch == '*') return 2;
        if(ch == '^') return 3;
        return -1;
    }

    string infixToPostfix(string& s) {
        stack<char> st;
        string ans = "";

        for(char ch : s) {
            if((ch >= 'A' && ch <= 'Z') ||
               (ch >= 'a' && ch <= 'z') ||
               (ch >= '0' && ch <= '9')) {
                ans.push_back(ch);
            }
            else if(ch == '(') {
                st.push(ch);
            }
            else if(ch == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else {
                while(!st.empty() && st.top() != '(' &&
                     (prec(st.top()) > prec(ch) ||
                     (prec(st.top()) == prec(ch) && ch != '^'))) {
                    ans.push_back(st.top());
                    st.pop();
                }

                st.push(ch);
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

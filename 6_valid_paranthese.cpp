//approach-using stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('a');
        for (int i = 0; i < s.size(); i++) {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                st.push(s[i]);
            else if ((st.top() == '(' && s[i] == ')')||(st.top() == '[' && s[i] == ']') ||(st.top() == '{' && s[i] == '}')) {
                st.pop();
                continue;
            }
            else    return false;
        }
        return st.top() == 'a';
    }
};

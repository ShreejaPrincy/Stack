//my code
//🧠 Key Observation (Redundant Brackets)
// - Carefully analyze the expression test cases. (Doitagain)
// - Brackets are not redundant if there is at least one operator (+, -, *, /) present between them.
// - Brackets are redundant if they directly close without enclosing any operator.

//Examples:
//   (a + b) → Not redundant
//   (a * (b + c)) → Not redundant
//   (a) or () → Redundant

//T.C - O(n)
//S.C - O(n)


bool findRedundantBrackets(string &s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++){

        if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')   st.push(s[i]);
        else if(s[i]==')'&&st.top()=='('){
            return true;
        }
        else if(s[i]==')'&&st.top()!='('){
            while(st.top()!='(')    st.pop();
            st.pop();
        }
    }
    
    return false;
}

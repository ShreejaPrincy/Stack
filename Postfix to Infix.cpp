//Time Complexity: O(n²)
//Reason: We traverse the expression once, but string concatenation copies characters, so in the worst case it can take O(n²).

//Space Complexity: O(n)
//Reason: Stack is used to store operands/sub-expressions. Total space used by the stack is O(n).
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<string> st;

    for(char ch : s) {
        if(isalnum(ch)) {
            st.push(string(1, ch));
        }
        else {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string temp = "(" + op2 + string(1, ch) + op1 + ")";
            st.push(temp);
        }
    }

    cout << st.top();
    return 0;
}

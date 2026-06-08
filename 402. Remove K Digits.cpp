// Time Complexity: O(n)
//
// We traverse the string once.
// Each digit is pushed and popped from the stack at most once.
// Removing leading zeros also takes O(n).
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// We use a string as a stack to store digits.
// In the worst case, all digits are stored in the stack.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char nums:num){
            while(!st.empty() && k>0 && st.back()-'0' >nums-'0'){
                st.pop_back();
                k--;
            }
            st.push_back(nums);
        }
        
        while(k>0){
            st.pop_back();
            k--;
        }

        int i=0;
        while(i<st.size() && st[i]=='0'){
            i++;
        }
        st=st.substr(i);
        return st.empty()?"0":st;
    }
};

// Time Complexity: O(n)
//
// We traverse the circular array virtually using a loop of size 2n.
// Each element is pushed and popped from the stack at most once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// The answer vector stores n elements.
// The stack can store up to n elements in the worst case.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for(int i = 2 * n - 1; i >= 0; i--) {
            int val = nums[i % n];

            while(!st.empty() && st.top() <= val) {
                st.pop();
            }

            if(i < n && !st.empty()) {
                nge[i] = st.top();
            }

            st.push(val);
        }

        return nge;
    }
};


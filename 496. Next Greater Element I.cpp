// Time Complexity: O(n + m)
//
// Here, n is the size of nums2 and m is the size of nums1.
// We traverse nums2 once to find the next greater element for every value.
// Each element is pushed and popped from the stack at most one time.
// After that, we traverse nums1 once to build the final answer using the map.
// Therefore, the overall time complexity is O(n + m).
//
// Space Complexity: O(n)
//
// The stack can store up to n elements in the worst case.
// The unordered_map stores the next greater element for each element of nums2.
// Therefore, the overall space complexity is O(n).


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            int val = nums2[i];

            while (!st.empty() && val >= st.top()) {
                st.pop();
            }

            if (st.empty()) {
                mp[val] = -1;
            } else {
                mp[val] = st.top();
            }

            st.push(val);
        }

        vector<int> nge;

        for (int val : nums1) {
            nge.push_back(mp[val]);
        }

        return nge;
    }
};

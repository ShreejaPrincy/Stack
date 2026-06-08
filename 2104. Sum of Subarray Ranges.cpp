//related to sum of subarray of minimum
// Time Complexity: O(n)
//
// We calculate next greater, previous greater, next smaller, and previous smaller using monotonic stacks.
// Each function traverses the array once.
// Each element is pushed and popped from the stack at most once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// We use arrays to store next greater, previous greater, next smaller, and previous smaller indices.
// We also use a stack that can store up to n indices in the worst case.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    vector<int> nge_fun(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[i] >= nums[st.top()])
                st.pop();

            if(!st.empty())
                nge[i] = st.top();

            st.push(i);
        }

        return nge;
    }

    vector<int> pge_fun(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[i] > nums[st.top()])
                st.pop();

            if(!st.empty())
                pge[i] = st.top();

            st.push(i);
        }

        return pge;
    }

    long long subarraymax(vector<int>& nums) {
        vector<int> nge = nge_fun(nums);
        vector<int> pge = pge_fun(nums);

        long long sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;

            sum += 1LL * nums[i] * left * right;
        }

        return sum;
    }

    vector<int> nse_fun(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[i] <= nums[st.top()])
                st.pop();

            if(!st.empty())
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> pse_fun(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[i] < nums[st.top()])
                st.pop();

            if(!st.empty())
                pse[i] = st.top();

            st.push(i);
        }

        return pse;
    }

    long long subarraymin(vector<int>& nums) {
        vector<int> nse = nse_fun(nums);
        vector<int> pse = pse_fun(nums);

        long long sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            sum += 1LL * nums[i] * left * right;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subarraymax(nums) - subarraymin(nums);
    }
};

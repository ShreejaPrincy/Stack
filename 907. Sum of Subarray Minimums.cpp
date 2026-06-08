// Time Complexity: O(n)
//
// We traverse the array once from right to left to find the next smaller element index.
// We traverse the array once from left to right to find the previous smaller element index.
// Each element is pushed and popped from the stack at most once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// We use two arrays, nse and pse, each of size n.
// The stack can store up to n indices in the worst case.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> next_smaller_index(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[i] <= a[st.top()])
                st.pop();

            if (!st.empty())
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> prev_smaller_index(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        vector<int> pse(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] < a[st.top()])
                st.pop();

            if (!st.empty())
                pse[i] = st.top();

            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = next_smaller_index(arr);
        vector<int> pse = prev_smaller_index(arr);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            sum = (sum + (1LL * arr[i] * left * right) % mod) % mod;
        }

        return sum;
    }
};

//approach
// 1. Remove elements outside current window
// 2. Remove smaller elements from back
// 3. Push current index
// 4. Store answer when window size becomes k

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int n=nums.size();

        for(int i=0;i<n;i++){

            while(!dq.empty()  && nums[dq.back()]<=nums[i]) 
                dq.pop_back();

            while(!dq.empty() && dq.front()<=i-k)
                dq.pop_front();

            dq.push_back(i);
            
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// Time Complexity: O(n)
//
// We traverse the array once.
// Each index is pushed into the deque at most once and popped at most once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(k)
//
// The deque stores indices of elements from the current window.
// In the worst case, it can store up to k indices.
// Therefore, the overall space complexity is O(k).
//

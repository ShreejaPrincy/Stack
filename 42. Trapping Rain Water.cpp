//Appproach - 1

// Time Complexity: O(n)
//
// We traverse the array three times:
// once to calculate the prefix maximum,
// once to calculate the suffix maximum,
// and once to calculate the trapped water at each index.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// We use two extra arrays, prefix_max and suffix_max, each of size n.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefix_max(n, 0);
        prefix_max[0] = height[0];

        for(int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], height[i]);
        }

        vector<int> suffix_max(n, 0);
        suffix_max[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i + 1], height[i]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans += min(prefix_max[i], suffix_max[i]) - height[i];
        }

        return ans;
    }
};


//Approach - 2
// Time Complexity: O(n)
//
// We use two pointers and each element is processed only once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(1)
//
// We only use a few variables such as left, right, leftMax, rightMax, and water.
// No extra array or stack is used.
// Therefore, the overall space complexity is O(1).

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0;

        int left=0;
        int right=n-1;

        int leftmax=0;
        int rightmax=0;

        while(left<=right){
            if(height[left]<=height[right]){
                if(leftmax>=height[left])
                    water+=leftmax-height[left];
                else
                    leftmax=height[left];
                left++;
            }
            else{
                if(rightmax>=height[right])
                    water+=rightmax-height[right];
                else
                    rightmax=height[right];
                right--;
            }
        }

        return water;
    }
};

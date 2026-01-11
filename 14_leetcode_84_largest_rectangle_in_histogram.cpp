//Approach-1
//⏱ Time       NSL → O(n)    NSR → O(n)
//             Total → O(n)
//🧠 Space     Stack + arrays → O(n)
//doitagain
//stuck at - “Since we are storing indices in the stack, we need to use a separate array for NSR inside the function.
//            Earlier, we were modifying the height array itself, so we were not able to correctly access height[i].”


class Solution {
public:
    int n = 0;
    vector<int> getNSR(vector<int> height) {
        vector<int>NSR(n);                   //*
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            if (st.empty())
                NSR[i] = n;
            else
                NSR[i] = st.top();

            st.push(i);
        }
        return NSR;
    }
    vector<int> getNSL(vector<int> height) {
        vector<int>NSL(n);                               //*
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            if (st.empty())
                NSL[i] = -1;
            else
                NSL[i] = st.top();

            st.push(i);
        }
        return NSL;
    }
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        vector<int> NSR = getNSR(heights);
        vector<int> NSL = getNSL(heights);
        int area = 0;
        for (int i = 0; i < n; i++) {
            cout << NSR[i] << " " << NSL[i] << " " << heights[i] << endl;
            int area_i = (NSR[i] - NSL[i] - 1) * heights[i];
            area = max(area, area_i);
        }
        return area;
    }
};


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Approach-2
//Time Complexity — O(n)
//Space Complexity — O(n)
//doitagain
    
  
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;   // store indices
        int area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int curr = (i == n ? 0 : heights[i]);

            while (!st.empty() && curr < heights[st.top()]) {
                int minimum = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;

                area = max(area, minimum * width);
            }
            st.push(i);
        }
        return area;
    }
};



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Time Complexity: O(n)
//
// We calculate next smaller element indices in O(n).
// We calculate previous smaller element indices in O(n).
// Then we traverse the array once to calculate the maximum rectangle area.
// Each element is pushed and popped from the stack at most once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// We use two arrays, nse and pse, each of size n.
// We also use a stack that can store up to n indices in the worst case.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    vector<int>nse_fun(vector<int>&arr){
        int n=arr.size();
        vector<int>nse(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>pse_fun(vector<int>&arr){
        int n=arr.size();
        vector<int>pse(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>nse=nse_fun(heights);
        vector<int>pse=pse_fun(heights);

        long long area=0;

        for(int i=0;i<n;i++){

            int width=nse[i]-pse[i]-1;
            int length=heights[i];

            area=max(area,1LL*width*length);
        }
        return (int)area;
    }
};



//Approach -2 

// Time Complexity: O(n)
//
// We traverse the histogram once.
// Each index is pushed into the stack at most once and popped at most once.
// The remaining elements in the stack are also processed once at the end.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// We use a stack to store indices of histogram bars.
// In the worst case, the stack can store up to n indices.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int area=0;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int curr_ele=heights[st.top()];
                st.pop();
                
                int nse=i;
                int pse=st.empty()?-1:st.top();

                area=max(area, (nse-pse-1)*curr_ele);
            }
            st.push(i);
        }

        while(!st.empty()){
            int curr_ele=heights[st.top()];
            st.pop();
            
            int nse=n;
            int pse=st.empty()?-1:st.top();

            area=max(area, (nse-pse-1)*curr_ele);
        }
        
        return area;
    }
};



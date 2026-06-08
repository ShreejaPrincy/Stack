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

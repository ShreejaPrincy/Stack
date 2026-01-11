//mycode
//“We convert each row into a histogram and compute the largest rectangle using NSL/NSR with a monotonic stack.”
//TC = O(rows × cols)
//SC = O(cols)  👉(Height + NSL + NSR + stack)


class Solution {
public:
    int cols;
    vector<int> getNSR(vector<int> &height) {
        vector<int>NSR(cols);
        stack<int> st;
        for (int i = cols - 1; i >= 0; i--) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            if (st.empty())
                NSR[i] = cols;
            else
                NSR[i] = st.top();

            st.push(i);
        }
        return NSR;
    }
    vector<int> getNSL(vector<int> &height) {
        vector<int>NSL(cols);
        stack<int> st;
        for (int i = 0; i < cols; i++) {
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
    int findarea(vector<int>&height){
        vector<int>NSR=getNSR(height);
        vector<int>NSL=getNSL(height);
        int area=0;
        for(int i=0;i<cols;i++){
            int area_i=height[i]*(NSR[i]-NSL[i]-1);
            area=max(area,area_i);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        cols=matrix[0].size();
        vector<int>height(cols,0);
        int area=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='0') height[j]=0;
                else    height[j]+=1;
            }
            area=max(area,findarea(height));
        }
        return area;
    }
};




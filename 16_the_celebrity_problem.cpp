//Approach - 1 
//T.C - O(n)
//S.C - O(n)
//using stack

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int i=st.top();
            st.pop();
            int j=st.top();
            st.pop();
            if(mat[i][j]==1)    st.push(j);
            else    st.push(i);
        }

        int c=st.top();
        for(int i=0;i<n;i++){
            if(mat[i][c]!=1&&i!=c)    return -1;
        }
        for(int i=0;i<n;i++){
            if(mat[c][i]!=0&&i!=c)    return -1;
        }
        return c;
    }
};


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  //Approach - 2 
  

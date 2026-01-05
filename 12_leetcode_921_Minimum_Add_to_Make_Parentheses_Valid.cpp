// APProach -1 

class Solution {
public:
    int minAddToMakeValid(string s) {
        int l=0,r=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') l++;
            else{
                if(l>0) l--;
                else    r++;
            }
        }
        return l+r;
    }
};



//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//APPROACH_2 (my)


class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()&&s[i]==')'&&st.top()=='(') st.pop();
            else  st.push(s[i]);
        }
        return st.size();
    }
};


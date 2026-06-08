// Time Complexity: O(n)
//
// We traverse the asteroids array once.
// Each asteroid is pushed into the stack at most once and popped at most once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// We use a vector as a stack to store the asteroids that are still alive.
// In the worst case, no collision happens, so the stack can store all n asteroids.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int i = 0; i < asteroids.size(); i++) {
            bool alive = true;
            int x = asteroids[i];

            while(alive && st.size() > 0 && st.back() > 0 && x < 0) {
                if(abs(x) > st.back()) {
                    st.pop_back();
                }
                else if(abs(x) == st.back()) {
                    st.pop_back();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }

            if(alive == true) {
                st.push_back(x);
            }
        }

        return st;
    }
};

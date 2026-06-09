// Time Complexity: O(1) amortized per next() call
//
// Each price is pushed into the stack once and popped from the stack at most once.
// Although one next() call may pop multiple elements, across all calls total push and pop operations are linear.
// Therefore, the amortized time complexity of each next() call is O(1).
//
// Space Complexity: O(n)
//
// The stack stores pairs of price and span.
// In the worst case, prices are strictly decreasing, so no elements are popped.
// Therefore, the stack can store up to n prices.

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};

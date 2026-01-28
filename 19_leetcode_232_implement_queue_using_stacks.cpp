// Queue using Two Stacks
// Time Complexity (Amortized):
// push() -> O(1)
// pop()  -> O(1)
// peek() -> O(1)
//
// Space Complexity: O(n)

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    int peek_element = -1;

    MyQueue() {}

    void push(int x) {
        if (input.empty())
            peek_element = x;
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        if (output.empty())
            return peek_element;
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

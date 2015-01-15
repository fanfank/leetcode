class MinStack { //sorry to use STL stack ...
public:
    void push(int x) {
        stack_all.push(x);
        
        if (stack_min.empty() || x <= getMin()) {
            stack_min.push(x);
        }
    }

    void pop() {
        int top_element = top();
        stack_all.pop();

        if (top_element == getMin()) {
            stack_min.pop();
        }
    }

    int top() {
        return stack_all.top();
    }

    int getMin() {
        return stack_min.top();
    }

private:
    stack<int> stack_all;
    stack<int> stack_min;
};

class Stack { 
private:
    queue<int> q;
    int top_element;

public: 
    // Push element x onto stack.  
    void push(int x) { 
        q.push(x);
        top_element = x;
    } 

    // Removes the element on top of the stack.  
    void pop() { 
        size_t count = q.size() - 1;
        while (count--) {
            push(q.front());
            q.pop();
        }
        q.pop();
    } 

    // Get the top element.  
    int top() { 
        return top_element;
    } 

    // Return whether the stack is empty.  
    bool empty() { 
        return q.empty();
    } 
};

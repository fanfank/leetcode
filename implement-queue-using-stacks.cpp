class Queue { 
public: 
    // Push element x to the back of queue.  
    void push(int x) { 
        s1.push(x);
    } 

    // Removes the element from in front of queue.  
    void pop(void) { 
        if (s2.empty()) {
            transfer_stack_data();
        }
        s2.pop();
    } 

    // Get the front element.  
    int peek(void) { 
        if (s2.empty()) {
            transfer_stack_data();
        }
        return s2.top();
    } 

    // Return whether the queue is empty.  
    bool empty(void) { 
        return s1.empty() && s2.empty();
    } 

private:
    stack<int> s1, s2; //s1 for push, s2 for pop

    void transfer_stack_data() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
};

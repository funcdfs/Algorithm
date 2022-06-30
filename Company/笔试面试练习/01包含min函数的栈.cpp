class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> minStack; 
    stack<int> valStack; 
    
    MinStack() {
        
    }
    
    void push(int x) {
        valStack.push(x); 
        
        if (minStack.empty() || x < minStack.top()) {
            minStack.push(x); 
        } else {
            minStack.push(minStack.top()); 
        }
    }
    
    void pop() {
        valStack.pop(); 
        minStack.pop(); 
    }
    
    int top() {
        return valStack.top(); 
    }
    
    int getMin() {
        return minStack.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
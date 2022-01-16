维护一个单调递减的单调栈，储存对于当前栈顶的最小值

``` cpp
class MinStack {
  public:
    /** initialize your data structure here. */
    stack<int> minStack;    // 维护一个单调栈，储存最小值
    stack<int> valStack;

    MinStack() {
        
    }

    void push(int x) {
        valStack.push(x);

        // 如果 push 的 x ，小于单调栈的最小值，则 x 对应的最小值就是 x 
        //                  否则，x 对应的单调栈的最小值就是 minStack.top()
        if (minStack.empty() || x < minStack.top()) 
            minStack.push(x);
        else
            minStack.push(minStack.top());
    }

    void pop() {
        // 同步弹出
        valStack.pop();
        minStack.pop();
    }

    int top() {
        return valStack.top();
    }

    int getMin() {
        return minStack.top();                      // 单调栈栈顶元素就是栈的最小值
    }
};
```
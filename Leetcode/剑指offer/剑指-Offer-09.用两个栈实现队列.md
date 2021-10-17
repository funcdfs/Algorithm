[题目链接](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)  
[题解链接](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/solution/jz09-fengwei2002-by-kycu-8skm/)

https://github.com/fengwei2002/algorithm

### 剑指 Offer 09. 用两个栈实现队列

用两个栈实现一个队列。

队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。（若队列中没有元素，deleteHead 操作返回 -1 )

### 思路

这是一道基础题，只要把功能实现对就可以，不需要考虑运行效率 $O(n)$。

我们用两个栈来做，一个主栈，用来存储数据；一个辅助栈，用来当缓存。

- `push(x)`，我们直接将 x 插入主栈中即可。
- `pop()`，此时我们需要弹出最先进入栈的元素，也就是栈底元素。我们可以先将**所有元素**从主栈中弹出，压入辅助栈中。则辅助栈的栈顶元素就是我们要弹出的元素，将其弹出即可。然后再将辅助栈中的元素全部弹出，压入主栈中。
- `peek()`，可以用和 `pop()` 操作类似的方式，得到最先压入栈的元素。
- `empty()`，直接判断主栈是否为空即可。

### C++

``` cpp
class CQueue {
   private:
    stack<int> stack1,stack2;
   public:
    CQueue() {
        // 执行清空队列的操作
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        // 如果第二个栈为空, 将第一个栈中的元素全部放入第二个栈中，相当于逆序
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        } 
        if (stack2.empty()) {
            return -1; // 如果将 stack1 中的数据放入 stack2 之后仍然为 空 返回 -1
        } else {
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
    }
};
```

TODO ### GO

``` go
type CQueue struct {

}

type CQueue struct {
    stack1, stack2 *list.List
}

func Constructor() CQueue {
    return CQueue{
        stack1: list.New(),
        stack2: list.New(),
    }
}

func (this *CQueue) AppendTail(value int)  {
    this.stack1.PushBack(value)
}

func (this *CQueue) DeleteHead() int {
    // 如果第二个栈为空
    if this.stack2.Len() == 0 {
        for this.stack1.Len() > 0 {
            this.stack2.PushBack(this.stack1.Remove(this.stack1.Back()))
        }
    }
    if this.stack2.Len() != 0 {
        e := this.stack2.Back()
        this.stack2.Remove(e)
        return e.Value.(int)
    }
    return -1
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
```
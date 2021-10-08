[题目链接](https://leetcode-cn.com/problems/peeking-iterator/)  
[题解链接](https://leetcode-cn.com/problems/peeking-iterator/solution/lc284-fengwei2002-c-ji-cheng-lei-2021-10-umv9/)

### 思路

在新的类 `PeekingIterator` 中缓存两个变量：int `_next`; 和 bool `_hasNext`; 分别存储下一个元素和是否存在下一个元素。

`PeekingIterator` 初始化时先更新这两个变量；

`peek()` 函数直接返回缓存的下一个元素 `_next；`

`hasNext()` 函数直接返回缓存的 `_hasNext；`

`next()` 函数稍微麻烦一点，需要返回缓存的 `_next`，同时不要忘记更新 `_next` 和 `_hasNext；`

如果想处理所有类型的迭代器，我们需要利用 C++中的 template 机制。

### 代码

```cpp
// Leetcode 题解区搜索 fengwei2002
// https://github.com/fengwei2002/algorithm

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *    public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
  public:
    int _next; // 用来存储下一个变量
    bool _hasNext; // 存储是否存在下一个元素

	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        _hasNext = Iterator::hasNext();
        if (_hasNext) _next = Iterator::next();
	}
	
	int peek() {
        return _next;
	}

	int next() {
	    int dummy = _next;
        _hasNext = Iterator::hasNext();

        if (_hasNext) _next = Iterator::next();
        return dummy;
	}
	
	bool hasNext() const {
	    return _hasNext;
	}
};
```
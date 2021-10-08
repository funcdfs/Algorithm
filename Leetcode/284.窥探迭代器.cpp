/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 窥探迭代器
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-05-08-16*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 *
 *
 */

// @lc code=start

// 下面是迭代器的接口，已经定义好，不要修改
class Iterator {
    struct Data;
    Data* data;

   public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // 返回迭代器的下一个元素
    int next();

    // 如果迭代器存在下一个元素，返回真值
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
   public:
    int _next; // 缓存两个变量，存储下一个元素
    bool _has_next; // 存储是否存在下一个元素

    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        _has_next = Iterator::hasNext(); // PeekingIterator 初始化时先更新这两个变量；
        if (_has_next) _next = Iterator::next();
    }

    // 返回迭代器的下一个元素，过程中不前进迭代器
    int peek() { return _next; } // peek() 函数直接返回缓存的下一个元素 _next；

    int next() { // next() 函数稍微麻烦一点，需要返回缓存的 _next，同时不要忘记更新 _next 和 _has_next；
        int ans = _next;
        _has_next = Iterator::hasNext(); // 更新 _has_next
        if (_has_next) _next = Iterator::next(); // 更新 next
        return ans;
    }

    bool hasNext() const { return _has_next; } // hasNext() 函数直接返回缓存的 _has_next；
};
// @lc code=end

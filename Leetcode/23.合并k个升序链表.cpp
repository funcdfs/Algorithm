/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
#include <algorithm>
#include <iostream>
#include <queue>  // 优先级队列，C++ 中的堆头文件
#include <vector>

using namespace std;

/*2021-10-02-18-20*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 ! 使用优先级队列（小顶堆）
 * 对于 stl 中类型特定的操作符重载
 *
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start

class Solution {
   public:
    struct Cmp {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        // 默认 priority_queue 是大顶堆， 这个题目中要使用小顶堆
        // 传入重载之后的比较函数
        // 第一个参数代表 queue 中存储的数据类型
        // 第二个参数代表 queue底层使用的容器，第三个参数代表自己自定义的比较参数

        auto dummy = new ListNode(-1), tail = dummy;

        for (auto l : lists)
            if (l) heap.push(l);
        // 放入堆中的数据已经按照从小到大进行了排序

        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            // 弹出堆顶最小的那一个 链表

            tail = tail->next = t;
            // 拼接到 tail 后面

            if (t->next) heap.push(t->next);
            // 再次放入 heap 中，这样每次取出来的 链表都是最小的那一个
        }

        return dummy->next;
    }
};
// @lc code=end

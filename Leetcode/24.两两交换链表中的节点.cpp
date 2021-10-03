/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-02-18-52*/

// from https://github.com/fengwei2002/Algorithm
/*
 ! 写链表题目还是直接画一个图，把题目要进行的操作mini一遍
 ! 观察具体逻辑，模拟即可
 * 列举一下具体需要几步，可以使用额外的节点进行数据存储，还原即可
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
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;

        for (auto p = dummy; p->next && p->next->next;) { // 不够 2 的倍数的部分就直接省略
            auto a = p->next, b = a->next;

            p->next = b; // 当前指针的下一个指针指向，下一个的下一个
            a->next = b->next; // 当前指针的下一个指针的下一个指针，指向 当前节点下一个的下一个的下一个的指针
            b->next = a; // 更新当前节点的下一个节点的下一个节点的下一个节点为 a 
            p = a; // a 是往后移动两个位置的指针
        }

        return dummy->next;
    }
};
// @lc code=end

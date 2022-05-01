/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-21-10-59*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list/solution/lc83-fengwei2002-by-kycu-0n25/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        auto cur = head;

        for (auto p = head->next; p; p = p->next)
            if (p->val != cur->val) cur = cur->next = p;

        cur->next = NULL;
        return head;
    }
};
// @lc code=end

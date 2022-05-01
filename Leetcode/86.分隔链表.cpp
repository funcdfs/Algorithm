/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-21-11-00*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/partition-list/solution/lc86-fengwei2002-by-kycu-4kri/

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
    ListNode* partition(ListNode* head, int x) {
        auto lh = new ListNode(-1);
        auto rh = new ListNode(-1);
        auto lt = lh, rt = rh;

        for (auto a = head; a; a = a->next) {
            if (a->val < x)
                lt = lt->next = a;
            else
                rt = rt->next = a;
        }

        lt->next = rh->next;
        rt->next = nullptr;
        return lh->next;
    }
};
// @lc code=end

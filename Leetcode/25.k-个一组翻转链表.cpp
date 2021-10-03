/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-02-20-01*/

// from https://github.com/fengwei2002/Algorithm

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto cur = dummy;

        while (cur != NULL) {
            auto first = cur->next;
            auto end = cur;

            for (int i = 0; i < k && end != NULL; i++) end = end->next;
            if (end == NULL) break; // 判断是否满足 >= k 的要求

            auto p1 = first;
            auto p2 = first->next;

            while (p1 != end) {
                auto newP2 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = newP2;
            }

            first->next = p2;
            cur->next = end;
            cur = first;
        }

        return dummy->next;
    }
};
// @lc code=end

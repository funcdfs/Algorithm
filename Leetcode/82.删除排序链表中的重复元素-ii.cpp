/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-21-11-07*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/solution/lc82-fengwei2002-by-kycu-uhzd/

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
        auto dummy = new ListNode(-1 ,head);
        auto a = dummy;

        while (a->next) {
            auto b = a->next;
            auto c = b->next;
            while (c && b->val == c->val) c = c->next;
            
            if (c == a->next->next) {
                a = a->next;
            } else {
                a->next = c;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

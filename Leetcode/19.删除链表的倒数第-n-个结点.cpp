/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-02-00-59*/

// from https://github.com/fengwei2002/Algorithm
/*
 !
 !
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/lc-19-fengwei2002-by-fengwei2002-e11l/
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* extHead = new ListNode(-1);
        extHead->next = head;

        ListNode* first = extHead;
        ListNode* second = extHead;

        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return extHead->next;
    }
};
// @lc code=end

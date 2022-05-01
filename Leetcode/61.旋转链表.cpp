/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-10-14-15-31*/

// depository:
// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/rotate-list/solution/lc61-fengwei2002-lian-biao-mo-ni-by-kycu-q859/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int n = 0;
        auto p = head;
        while (p) {
            n++;
            p = p->next;
        }

        k %= n;
        if (k == 0) return head;

        // 现在 k 就是一个小于 n 的数字了 ,n 为链表的总长度

        // 找到倒数 第 k 个节点，
        int recKIndex = n - k;
        auto p2 = head;
        while (p2) {
            recKIndex--;
            p2 = p2->next;
        }
        ListNode* recK = p2;
        cout << recK->val << endl;
        return recK;
    }
};
// @lc code=end

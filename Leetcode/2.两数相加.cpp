/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-25-23-39*/
// ? 思路解析：
/*
 *
 *  从个位开始累加，累加值合并到 t 中，
 *     然后使用 进位值构建结果链表
 !
 !
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        int t = 0;
        while (l1 || l2 || t > 0) {
            if (l1) {
                t += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                t += l2->val;
                l2 = l2->next;
            }

            if (head == nullptr) {
                head = tail = new ListNode(t % 10);
            } else {
                tail->next = new ListNode(t % 10);
                tail = tail->next;
            }

            t /= 10;
        }
        return head;
    }
};
// @lc code=end

class Solution2 {
   public:
    ListNode* addTwoNumbers(ListNode* list_1, ListNode* list_2) {
        ListNode* head = nullptr;
        ListNode* tail = head;

        int t = 0;
        while (list_1 || list_2 || t > 0) {
            if (list_1) {
                t += list_1->val;
                list_1 = list_1->next;
            }
            if (list_2) {
                t += list_2->val;
                list_2 = list_2->next;
            }

            if (head == nullptr) {
                head = tail = new ListNode(t % 10);
            } else {
                tail->next = new ListNode(t % 10);
                tail = tail->next;
            }

            t /= 10;
        }

        return head;
    }
};
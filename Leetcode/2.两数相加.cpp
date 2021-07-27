/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-27-19-14*/
// ? 思路解析：
/*
 *
 *
 *
 *
 ! --难点：
 ! -- 注意 listnode 的写法即可
 ! -- 同加法运算
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

        int container = 0;

        while (l1 != nullptr || l2 != nullptr || container > 0) {
            if (l1 != nullptr) {
                container += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                container += l2->val;
                l2 = l2->next;
            }
            // printf("container == %d\n", container);
            if (head == nullptr) {
                head = tail = new ListNode(container % 10);
            } else {
                tail->next = new ListNode(container % 10);
                tail = tail->next;
            }
            container /= 10;
            // printf("container == %d\n", container);
        }
        return head;
    }
};
// @lc code=end

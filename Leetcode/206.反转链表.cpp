/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-27-19-35*/
// ? 思路解析：
/*
 *
 *
 *
 *
 ! --难点： C++ 操作链表的语法
 ! --
 ! --
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; 
        // 是指针型的变量
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev; // 当前节点的下一个节点指向前节点
            prev = curr; // 前节点更新为当前节点
            curr = next; // 当前节点右移到 next 上
        }
        return prev; // 返回最后一个节点
    }
};

// @lc code=end

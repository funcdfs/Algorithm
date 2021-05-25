/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 链表（Linked List）是一种常见的基础数据结构，
// 是一种线性表，但是并不会按线性的顺序存储数据，
// 而是在每一个节点里存到下一个节点的指针（Pointer）。所以不能直接方括号访问
// 用每一种语言的时候力扣会在题目上方的注释中列出相关数据结构的基础接口

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //遍历半个数据块和后面的进行空间交换
        m = m - 1;
        n = n - 1;

        if (m == n) {
            return head;
        }
        for (size_t i = m; i <= m + (n - m) / 2; i++) {
            ListNode* temp = head;
            for (size_t j = 0; j < i; j++) {
                temp = temp->next;
            }
            int temp = temp->val;  //提取数据值
        }
        return head;
    }
};
// @lc code=end

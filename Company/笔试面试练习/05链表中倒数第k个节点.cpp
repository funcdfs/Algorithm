// Problem: 链表中倒数第k个节点
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/32/
// date: 2022-03-30 10:26:13
// Memory Limit: 64 MB
// Time Limit:   1000 ms

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) {
        int n = 0; 
        for (auto p = head; p != nullptr; p = p->next) {
            n++; 
        }
        // 统计总长度
        
        if (n < k) return nullptr; 
        auto p = head; 
        for (int i = 0; i < n - k; i++) {
            p = p->next; 
        }
        // 然后让头节点向后走 n - k 步 
        
        return p; 
    }
};


// 第二种方法：

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findKthToTail(ListNode* head, int k) {
        auto fast = head; 
        auto slow = head; 
        
        while (k--) {
            if (fast != nullptr) fast = fast->next; 
            else return nullptr; 
        }
        
        while (fast != nullptr) {
            slow = slow->next; 
            fast = fast->next; 
        }
        
        return slow; 
    }
};
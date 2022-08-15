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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }  
        
        auto tail = reverseList(head->next); 
        head->next->next = head; 
        head->next = nullptr; 
        
        return tail; 
    }
};


/* ----------------------------  迭代 */ 

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        } 
        auto a = head; 
        auto b = head->next; 
        
        while (b != nullptr) {
            auto c = b->next; 
            b->next = a; 
            a = b; 
            b = c;
        } 
        
        head->next = nullptr; 
        
        return a; 
    }
};
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
    ListNode *entryNodeOfLoop(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; 
        }
        auto slow = head; 
        auto fast = head; 
        
        while (fast && fast->next) {
            fast = fast->next->next; 
            slow = slow->next; 
            
            if (fast == slow) {
                slow = head; 
                
                while (fast != slow) {
                    slow = slow->next; 
                    fast = fast->next; 
                } 
                
                return fast; 
            }
        }
        
        return nullptr;
    }
};
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
    ListNode* quickSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }         
        
        ListNode* left = new ListNode(-1); 
        ListNode* mid =  new ListNode(-1); 
        ListNode* right = new ListNode(-1); 
        
        auto leftTail = left; 
        auto midTail = mid; 
        auto rightTail = right; 
        
        int val = head->val; 
        
        for (auto p = head; p; p = p->next) {
            if (p->val < val) {
                leftTail->next = p; 
                leftTail = leftTail->next; 
            } else if (p->val == val) {
                midTail->next = p; 
                midTail = midTail->next; 
            } else {
                rightTail->next = p; 
                rightTail = rightTail->next; 
            }  
        } 
        // 将值拼接在三个列表后面 
        
        
        leftTail->next = nullptr; 
        rightTail->next = nullptr; 
        midTail->next = nullptr; 
        // 断开三个列表 
        
        
        left->next = quickSortList(left->next); 
        right->next = quickSortList(right->next); 
        // 将列表左侧和右侧的内容进行递归排序 
        
        
        getTail(left)->next = mid->next; 
        getTail(left)->next = right->next; 
        // 拼接三个列表 
         
        auto p = left->next; 
        delete left; 
        delete mid; 
        delete right; 
        
        return p; 
    } 
    ListNode* getTail(ListNode* p) {
        while (p->next) {
            p = p->next; 
        } 
        return p; 
    }
};
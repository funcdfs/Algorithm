// Problem: 删除链表中重复的节点
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/27/
// date: 2022-07-24 11:42:21
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */
// for debug:
// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;





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
    ListNode* deleteDuplication(ListNode* head) {
     	auto dummyHead = new ListNode(-1); 
    	dummyHead->next = head; 
    	
    	auto cur = dummyHead; 
    	
    	while (cur->next != nullptr) {
    	    auto p = cur->next; 
    	    while (p && p->next && p->val == p->next->val) {
    	        p = p->next; 
    	    } 
    	    p = p->next; 
    	    if (cur->next->next == p) {
    	        cur = cur->next; 
    	    } else {
    	        cur->next = p; 
    	    }
    	}
    	
    	return dummyHead->next; 
    }
};

/*
排序链表中删除所有出现多次的删除 

这个问题中的头节点可能会被删除，

在头节点可能被删除的时候，经常会定义一个虚拟节点来简化代码

第一个指针保留上一段的结尾 p

第二个指针用来保留下一段的第一个节点 q

*/





int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    
    
    return 0;
}
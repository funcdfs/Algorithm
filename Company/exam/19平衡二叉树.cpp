// Problem: 平衡二叉树
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/68/
// date: 2022-04-21 20:07:32
// Memory Limit: 64 MB
// Time Limit:   1000 ms
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool ans = true; 
    
    bool isBalanced(TreeNode* root) {
        // 判断这个树是不是平衡二叉树 
        dfs(root); 
        return ans; 
    }
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0; 
        int left = dfs(root->left); 
        int right = dfs(root->right); 
        
        if (abs(left - right) > 1) ans = false; 
        
        return max(left, right) + 1; 
    }
};
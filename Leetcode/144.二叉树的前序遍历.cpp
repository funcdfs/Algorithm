/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*2021-09-13-21-15*/
// ? 思路解析：
/*
 *
 *
 !
 !
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
    void traversal(TreeNode *cur, vector<int> &ans) {
        if (cur == NULL) return;
        ans.push_back(cur->val); 
        traversal(cur->left, ans);
        traversal(cur->right, ans);
    }
};
// @lc code=end

class Solution_迭代解法 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        
        if (root == NULL) return ans;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);
            
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return ans;
    }
};
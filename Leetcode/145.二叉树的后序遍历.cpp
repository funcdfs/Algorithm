/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*2021-09-13-23-09*/
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 后续遍历在，前序遍历的基础上, 多加一个 逆序输出即可

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // stack<TreeNode*> st;
        // vector<int> result;

        // if (root == NULL) return result;
        // st.push(root);
        
        // while (!st.empty()) {
        //     TreeNode *node = st.top();
        //     st.pop();
        //     result.push_back(node->val);

        //     if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 
        //     if (node->right) st.push(node->right); // （空节点不入栈）
        // }
        // reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        // return result;








        // stack<TreeNode *> st;
        // vector<int> ans;

        // if (root == NULL) return ans;
        // st.push(root);

        // while (!st.empty()) {
        //     TreeNode *node = st.top();
        //     st.pop();
        //     ans.push_back(node->val); 

        //     if (node->right) st.push(node->right);
        //     if (node->left) st.push(node->left);
        // }
        // return ans;    前序遍历
        
        






        // stack<TreeNode *> st;
        // vector<int> ans;

        // TreeNode *cur = root;
        // while (cur != NULL || !st.empty()) {
        //     if (cur != NULL) {
        //         st.push(cur);
        //         cur = cur->left;
        //     } else {
        //         cur = st.top();
        //         st.pop();
        //         ans.push_back(cur->val);

        //         cur = cur->right;
        //     }
        // }                  中序遍历










        // stack<TreeNode*> st;
        // vector<int> ans;

        // if (root == NULL) return ans;  
        // st.push(root);

        // while (!st.empty()) {
        //     TreeNode *node = st.top();
        //     st.pop();
        //     ans.push_back(node->val);
        //     // 前序遍历：中左右
        //     // 后序遍历：左右中，逆序之后：中右左
        //     if (node->left) st.push(node->left);
        //     if (node->right) st.push(node->right);
        // }
        // reverse(ans.begin(), ans.end()); 后序遍历迭代写法
    }

};
// @lc code=end


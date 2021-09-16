/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*2021-09-16-08-36*/
// ? 思路解析：
/* 
 * 
 *  二叉树层次遍历模板题
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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;  

        if (root != NULL) que.push(root);  
        while (!que.empty()) {
            int size = que.size();
            int maxval = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                maxval = max(node->val, maxval);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};
// @lc code=end


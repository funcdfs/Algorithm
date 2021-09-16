/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*2021-09-14-10-45*/
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<TreeNode *> que;

        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();

                if (i == (size - 1)) ans.push_back(node->val);
                
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return ans;
    }
};
// @lc code=end

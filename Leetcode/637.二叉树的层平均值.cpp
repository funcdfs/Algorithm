/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*2021-09-16-08-03*/
// ? 思路解析：
/*
 *
 *
 ! 二叉树 层次遍历 模板题 
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
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> que;
        vector<double> ans;

        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double sum = 0, nums = 0, average = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val, nums++;

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            average = sum / nums; 
            ans.push_back(average);
        }
        return ans; 
    }
};
// @lc code=end

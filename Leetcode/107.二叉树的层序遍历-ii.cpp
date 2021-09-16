/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*2021-09-14-10-34*/
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

class Solution {
   public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> que;
        vector<vector<int>> ans;

        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> item;

            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                item.push_back(node->val);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            // reverse(item.begin(), item.end());
            ans.push_back(item);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

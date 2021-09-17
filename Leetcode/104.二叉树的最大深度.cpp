/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*2021-09-16-17-25*/
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

class Solution_循环写法 {
   public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            depth++;  // 记录深度
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};

// @lc code=end

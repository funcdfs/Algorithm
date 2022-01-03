/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-12-06-17-53*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/solution/lc129-fengwei2002-by-kycu-jr9s/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start


class Solution {
public:
    int ans = 0;

    int sumNumbers(TreeNode* root) {
        if (root) dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int number) {
        number = number * 10 + root->val;
        if (!root->left && !root->right) ans += number;
        if (root->left) dfs(root->left, number);
        if (root->right) dfs(root->right, number);
    }
};
// @lc code=end


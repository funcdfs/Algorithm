/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-17-23-15*/
// ? 思路解析：
/*
 *
 *  树哈希。
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
    bool dfs(TreeNode *s, TreeNode *t) {
        if (!s) return false;

        return isSame(s, t) || dfs(s->left, t) || dfs(s->right, t);
    }

    bool isSame(TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if (!s && t || s && !t || s->val != t->val) return false;

        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }

    bool isSubtree(TreeNode *s, TreeNode *t) { return dfs(s, t); }
};
// @lc code=end

class Solution_树哈希 {
   public:
    const int P = 131, Q = 159, MOD = 1e7 + 7;
    int T = -1;
    bool ans = false;

    int dfs(TreeNode *root) {
        if (!root) return 12345;  //
        int left = dfs(root->left), right = dfs(root->right);
        // 计算左右子树的哈希值
        int x = (root->val % MOD + MOD) % MOD;
        // 取正数
        if (left == T || right == T) ans = true;
        return (x + left * P % MOD + right * Q) % MOD;
    }

    bool isSubtree(TreeNode *s, TreeNode *t) {
        T = dfs(t);
        if (T == dfs(s)) ans = true;
        return ans;
    }
};
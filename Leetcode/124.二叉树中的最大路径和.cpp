/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*2021-12-04-22-20*/

// https://github.com/fengwei2002/Algorithm
// solution link: 
// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/lc124-fengwei2002-by-kycu-xg9w/

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
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* u) {
        if (u == nullptr) {
            return 0;
        }
        int left = max(0, dfs(u->left));
        int right = max(0, dfs(u->right));
        ans = max(ans, u->val + left + right);
        
        return u->val + max(left, right);    
    }
};
// @lc code=end


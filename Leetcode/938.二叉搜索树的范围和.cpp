/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */

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

// 题解：https://leetcode-cn.com/problems/range-sum-of-bst/solution/cjian-ji-dai-ma-di-gui-by-orangeman/
// struct TreeNode {
//     /*每一个node拥有值，以及左右节点的信息*/
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     // 这里是构造函数
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     // 尾节点的构造函数k
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     // 正常节点的构造函数
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution {
   public:
    int rangeSumBST(TreeNode *root, int L, int R) {
                if (!root) return 0;
        // 如果在范围内，
        if (root->val >= L && root->val <= R)
            return rangeSumBST(root->left, L, R) +
                   rangeSumBST(root->right, L, R) + root->val;
        // 不在范围内的话
        else
            return rangeSumBST(root->left, L, R) +
                   rangeSumBST(root->right, L, R);
    }
};
// @lc code=end

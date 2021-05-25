/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

// @lc code=start
// struct TreeNode {
//     /*每一个node拥有值，以及左右节点的信息*/
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     // 这里是构造函数
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     // 尾节点的构造函数
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     // 正常节点的构造函数
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution {
   public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return NULL;
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        TreeNode *combine = new TreeNode;
        combine->val = 0;
        combine->val = root1->val + root2->val;
        combine->left = mergeTrees(root1->left, root2->left);
        combine->right = mergeTrees(root1->right, root2->right);
        return combine;
    }
};
// @lc code=end

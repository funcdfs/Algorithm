/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*2022-01-01-19-13*/

// https://github.com/fengwei2002/Algorithm
// solution link:
// on: https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/solution/jian-kong-er-cha-shu-by-leetcode/
// ologn: 使用前序遍历和中序遍历
// myLink: https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/solution/lc1008-fengwei2002-by-kycu-gztq/

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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int n = preorder.size();
        TreeNode *dummy = new TreeNode(INT_MAX);
        stack<TreeNode *> stk;

        stk.push(dummy);
        TreeNode *cur = dummy;

        for (int i = 0; i < n; i++) {
            TreeNode *newNode = new TreeNode(preorder[i]);
            // 根据前序遍历的顺序构建一个节点

            if (newNode->val < cur->val) {
                cur->left = newNode;
            } else {
                while (stk.top()->val < newNode->val) {
                    cur = stk.top();
                    stk.pop();
                }
                cur->right = newNode;
            }

            stk.push(newNode);
            cur = newNode;
        }

        return dummy->left;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-18-16-55*/
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        auto l = root->left, r = root->right;
        int x = 1, y = 1;
        while (l) l = l->left, x ++ ;
        while (r) r = r->right, y ++ ;
        if (x == y) return (1 << x) - 1;
        
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
// @lc code=end
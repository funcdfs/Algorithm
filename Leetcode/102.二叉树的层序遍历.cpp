/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>



using namespace std;
/*2021-09-14-10-12*/
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


// 3 9 20 15 7  第一层的媒体一个节点放入，同时将每一个节点的左右节点放入，
// 由于栈先进先出的特点， 第一层遍历完之后就是从第二层的最左侧开始遍历， 输出就是层次遍历的结果
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> que; 
        vector<vector<int> >ans;

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
            ans.push_back(item);
        }
        return ans;
    }
};

// @lc code=end


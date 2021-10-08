/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
/*2021-09-21-09-57*/
// ? 思路解析：
/* 
 * 
 * 
 ! 
 ! 
 */


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// @lc code=start

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right)
//         : val(x), left(left), right(right){};
// };

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// @lc code=end

class Solution_前序遍历 {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();  // 中
            st.pop();

            swap(node->left, node->right); // 节点处理
            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);    // 左
        }
        return root;
    }
};


class Solution_层次遍历 {
   public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                swap(node->left, node->right);  // 节点处理
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};

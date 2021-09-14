/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*2021-09-13-22-45*/
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

//!  使用迭代法写中序遍历，就需要借用 指针的遍历 来帮助访问节点，栈则用来   处理节点上的元素

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*> st;
        vector<int> ans;
        
        
        // 先将所有的左节点放入栈中
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {  // 遍历顺序  左中右
            if (cur != NULL) {     // 当前指针不为空的话， 指针来访问节点，访问到最底层（所有左节点的那一层）
                st.push(cur);      
                cur = cur->left;
            } else {
                cur = st.top();    // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                ans.push_back(cur->val);        // 中
                
                cur = cur->right;               // 指向右，然后再 将这一个右节点作为根节点的 所有左节点放入，直到访问到最底层（没有左节点的那一层）
            }
        }
        while (cur != NULL || st.empty() != 0) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                ans.push_back(cur->val);

                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end


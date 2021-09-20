/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>  
#include <stack>

using namespace std;
/*2021-09-17-22-27*/
// ? 思路解析：
/*
 *
 * 二叉树，dfs
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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};
// @lc code=end

class Solution_分开的写法 {
   public:
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == NULL && right != NULL)
            return false;
        else if (left != NULL && right == NULL)
            return false;
        else if (left == NULL && right == NULL)
            return true;
        else if (left->val != right->val)
            return false;

        else
            return compare(left->left, right->right) &&
                   compare(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};

class Solution_迭代队列解法 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);   // 将左子树头结点加入队列
        que.push(root->right);  // 将右子树头结点加入队列

        while (!que.empty()) {  // 接下来就要判断这两个树是否相互翻转
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            if (!leftNode && !rightNode) {  // 左节点为空、右节点为空，此时说明是对称的
                continue;
            }

            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            que.push(leftNode->left);   // 加入左节点左孩子
            que.push(rightNode->right); // 加入右节点右孩子
            que.push(leftNode->right);  // 加入左节点右孩子
            que.push(rightNode->left);  // 加入右节点左孩子
        }
        return true;
    }
};
// 迭代法，其实是把左右两个子树要比较的元素顺序放进一个容器，
// 然后成对成对的取出来进行比较，那么其实使用栈也是可以的。


class Solution_栈解法 {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> st; // 这里改成了栈
        st.push(root->left);
        st.push(root->right);

        while (!st.empty()) {
            TreeNode* leftNode = st.top(); st.pop();
            TreeNode* rightNode = st.top(); st.pop();
            if (!leftNode && !rightNode) {
                continue;
            }
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }
        return true;
    }
};

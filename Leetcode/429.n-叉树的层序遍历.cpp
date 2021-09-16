/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*2021-09-16-08-21*/
// ? 思路解析：
/*
 *
 * 二叉树层次遍历模板题
 !
 !
 */

class Node {
   public:
    int val;
    vector<Node*> children;  // 每一个 node 拥有，val 和 一排儿子节点

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start

// Definition for a Node.

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> ans;

        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> item;
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                item.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++)
                    que.push(node->children[i]);
            }
            ans.push_back(item);
        }
        return ans;
    }
};
// @lc code=end

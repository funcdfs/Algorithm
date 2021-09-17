/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*2021-09-16-08-44*/
// ? 思路解析：
/*
 *
 * 二叉树层次遍历模板题
 !
 ! 二叉树
 */

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

// Definition for a Node.
class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return root;
        auto source = root;
        while (root->left) {  // 如果还有下一层就继续更新
            for (auto p = root; p; p = p->next) {
                p->left->next = p->right;
                // 当前节点左儿子的 next 指向右节点
                if (p->next) p->right->next = p->next->left;
                // 当前节点的右儿子的 next 指针指向当前节点 next 的左儿子
            }
            root = root->left;  // 切换到下一层
        }
        return source;
    }
};

// @lc code=end
class Solution_二叉树层次遍历 {
   public:
    Node* connect(Node* root) {
        Node* ans = root;
        queue<Node*> que;

        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            Node* node = new Node(-1);
            Node* nodePre = node;

            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                } else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            nodePre->next = NULL;
        }
        return ans;
    }
};
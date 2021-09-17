/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*2021-09-16-09-26*/
// ? 思路解析：
/*
 *
 * 二叉树层次遍历模板题
 !
 !
 */

// Definition for a Node.
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

class Solution {
   public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            Node* nodePre = new Node(-1);
            Node* node = nodePre;

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

            nodePre->next = NULL;  // 本层最后一个节点指向NULL
        }
        return root;
    }
};
// @lc code=end

class Solution_yxc {
   public:
    Node* connect(Node* root) {
        auto source = root;

        while (root) {
            Node* head = new Node(-1);
            Node* tail = head;

            while (root) {
                if (root->left) {
                    tail->next = root->left;
                    tail = tail->next;
                }
                if (root->right) {
                    tail->next = root->right;
                    tail = tail->next;
                }
                root = root->next;
            }
            root = head->next;
        }
        return source;
    }
};
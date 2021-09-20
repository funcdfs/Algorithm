/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-09-18-14-05*/
// ? 思路解析：
/* 
 * 
 * 
 ! 
 ! 
 */

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start


class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int maxVal = 0;
        for (auto c : root->children) {
            maxVal = max(maxVal, maxDepth(c));
        }
        return maxVal + 1;
    }
};
// @lc code=end


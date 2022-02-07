// Problem: 序列化二叉树
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/46/
// date: 2022-02-05 18:40:33
// Memory Limit: 64 MB
// Time Limit: 1000 ms

/* @ https://github.com/fengwei2002/Algorithm */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        dfs_s(root, ans);
        return ans;
    }
    void dfs_s(TreeNode* root, string& ans) {
        if (!root) {
            ans += "null ";
            return;
        }
        ans += to_string(root->val) + ' ';
        dfs_s(root->left, ans);
        dfs_s(root->right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
        // 可以使用的原因是：可以知道每个节点是否到头了，null
        // 之后就没有其他的元素了
    }

    TreeNode* dfs_d(string data, int& u) {
        if (u == data.size()) return nullptr;
        int k = u;
        while (data[k] != ' ') k++;  // u 到 k 就是一个具体的数字
        if (data[u] == 'n') {        // 如果这个具体的节点为空的话
            u = k + 1;               // 考虑下一个节点
            return nullptr;
        }
        int val = 0;  // 用 cal 存储这个节点的具体的值
        int sign = 1;
        if (u < k && data[u] == '-') sign = -1, u++;
        for (int i = u; i < k; i++) {
            val = val * 10 + data[i] - '0';
        }
        val *= sign;
        u = k + 1;
        // 顺次考虑下一个节点

        auto root = new TreeNode(val);
        // 根据这个值构造一个节点

        root->left = dfs_d(data, u);
        root->right = dfs_d(data, u);

        return root;
    }
};

// Problem: 二叉树遍历
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1261/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// date: 2022-02-04 17:17:24

/* @ https://github.com/fengwei2002/Algorithm */

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

struct Node {
	char val;
	Node* left, *right;
	Node(char _val) : val(_val), left(nullptr), right(nullptr) {}
};

string ans;


void dfs(Node* root) {
	if (!root) return;
	ans += root->val;
	dfs(root->left);
	dfs(root->right);
}

typedef long long unsigned int LLUI;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	
	string inorder, lorder;
	cin >> inorder >> lorder;   // 读入中序遍历和层序遍历
	
	unordered_map<char, LLUI> pos;
	for (LLUI i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
								// 用哈希表记录中序遍历中每个值具体出现的位置
	vector<bool> st(30, false); // st 数组用来记录中序遍历中的每一个位置是否被遍历过
	Node* q[30];  				// 因为要在队列中进行不同位置元素的读取，所以使用数组模拟更加合适
	q[0] = new Node(lorder[0]);
	
	for (LLUI i = 0, j = 1; j < lorder.size();) {
		LLUI end = j;			// i 为第一层的起点，j 为第二层的起点
		for (; i < end; i++) {  // 遍历第一层中的每一个元素
			LLUI p = pos[lorder[i]];
			st[p] = true;
			if (p > 0 && !st[p - 1]) { // 如果在层序遍历中的这一个元素在中序遍历中的左侧存在元素
				q[i]->left = new Node(lorder[j]);
									   // 依次构建二叉树
				q[j] = q[i]->left;     // 同时将构建好的二叉树放入队列中，用于下次取出
				j++;				   // 同时第二层的下标 j 可以向后移动一位
			}
			if (p + 1 < lorder.size() && !st[p + 1]) {
				q[i]->right = new Node(lorder[j]);
				q[j] = q[i]->right;
				j++;
			}
		}
	}
	
	dfs(q[0]);                 // 通过前序遍历输出二叉树
	
	cout << ans << endl;
	
    return 0;
}


    // 给出中序遍历和层序遍历的结果，求该树的前序遍历的结果
    // 包含 n 个节点的二叉树的种类数量一共有卡特兰数个
    // 序列化二叉树
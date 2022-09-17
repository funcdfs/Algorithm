// Problem: 求导弹防御系统数量，可以防御两个方向
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/189/
// date: 2022-07-22 19:12:36
// Memory Limit: 64 MB
// Time Limit: 3000 ms


/* https://github.com/fengwei2002/algorithm */
// for dbg:
// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 55; 

int n; 
int q[N]; 
int up[N]; // 上升子序列的结尾
int down[N]; // 下降子序列的结尾
int ans; 

void dfs(int u, int su, int sd) {
	// 第一个是当前枚举到了第几个数，
	// 第二个是当前上升子序列的个数
	// 第三个是当前下降子序列的个数 
	if (su + sd >= ans) return; 
	
	if (u == n) {
		ans = su + sd; // 只要能下来，说明 su + sd 一定是小于 ans 的
		return; 
	}	 
	
	// 情况1 将当前数字放到上升子序列中 
	int k = 0; 
	while (k < su && up[k] >= q[u]) k++; 
	int t = up[k]; 
	up[k] = q[u]; // 备份
	
	if (k < su) {
		dfs(u + 1, su, sd); 
	} else {
		dfs(u + 1, su + 1, sd); 
	}
	up[k] = t;  // 恢复现场 
	
	// 情况2 将当前数字下降子序列中 
	k = 0; 
	while (k < sd && down[k] <= q[u]) k++; 
	t = down[k]; 
	down[k] = q[u]; 
	
	if (k < sd) {
		dfs(u + 1, su, sd); 
	} else {
		dfs(u + 1, su, sd + 1); 
	}
	down[k] = t; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (cin >> n, n) {
    	for (int i = 0; i < n; i++) cin >> q[i]; 
    	ans = n; // 最坏情况下，ans 就是每一个导弹分配一个防御系统，n
    	dfs(0, 0, 0); 
    	
    	cout << ans << endl; 
    }
    
    return 0;
}

/*

这个导弹，每次可以单调递增，也可以单调下降

问最少需要多少个防御系统，才可以构成一个完整的防御

也就是最少可以使用多少个上升子序列和下降子序列才可以把整个序列覆盖掉 
	
	对于每一个数字，变成了四种可能出现的情况
	
	情况1 
		如果现有的子序列的结尾都小于当前数字，则创建新的子序列
	情况2
		把当前数，放到结尾大于等于他的集合中结尾元素最小的子序列的后面
	情况3（单调递增的防御系统）
		如果现有的子序列的结尾都大于当前数字，则创建新的子序列
	情况4（单调递增的防御系统）
		把当前数字放到结尾小于等于当前数字的结合中，结尾元素最大的子序列的后面
*/
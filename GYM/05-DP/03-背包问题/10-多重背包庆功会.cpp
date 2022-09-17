// Problem: 庆功会
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1021/
// date: 2022-07-25 16:11:43
// Memory Limit: 64 MB
// Time Limit: 1000 ms


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








const int N = 6010; 

int n, m; 
int f[N]; 


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
	cin >> n >> m; 
	
	for (int i = 0; i < n; i++) {
		int v, w, s; 
		// 每一个物品读入体积价值和数量
		cin >> v >> w >> s; 
		
		for (int j = m; j >= 0; j--) {
			for (int k = 0; k <= s && k * v <= j; k++) {
				f[j] = max(f[j], f[j - k * v] + k * w); 
			}
		}
	}    
    
    cout << f[m] << endl; 
    
    return 0;
}


/*

每一个物品有限个，输出可以获得的最大价值

所以是一个多重背包问题
暴力多重背包的时间复杂度
物品个数*背包总容量*每个物品的物品个数

状态表示: 
f[i][j] 表示使用前 i 中物品，背包容量为 j 的时候，可以得到的最大价值 

状态计算: 
f[i][j] = max(f[i - 1][j - v[i]*k] + w[i]*k)

由于每一个轮次使用的 都是同一轮次中，编号更小的，也就是编号更小的应该被后更新

所以去除一维状态之后，应该是 i 顺序遍历，j 从 m 开始逆序遍历

*/
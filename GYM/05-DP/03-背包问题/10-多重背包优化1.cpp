// URL: https://www.acwing.com/problem/content/description/4/
// Problem: 多重背包问题 I, Contest: AcWing
// Mem 64 MB, Time 1000 ms
// Date: 2022-08-02 22:22:31

/*
f[i][j] 所有只从前 i 个物品中选择， 并且总体积不超过 j 的选法 

max

最多选择 s[i] 类 

状态计算: 

f[i,j] = max(f[i-1,j], f[i-1][j-v[i]*k]+w[i]*k); 


*/

#include <iostream>
#include <algorithm>
using namespace std; 

const int N = 110; 

int n, m; 
int v[N], w[N], s[N]; 
int f[N][N]; 

int main() {
	cin >> n >> m; 
	
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i]; 
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= s[i] && k * v[i] <= j; k++) {
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]*k] + w[i]*k); 
			}
		}
	}
	cout << f[n][m] << endl; 
	
	return 0; 
	
	return 0; 
}
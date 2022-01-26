// Problem: P2241 统计方形（数据加强版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2241
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// date: 2022-01-25 17:22:30

/*
 @ KONNG
 @ https://github.com/fengwei2002/Algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	
	// ###
	// ###
	
	// 矩形的数量 == 正方形的数量加上长方形的数量
	 
	// 算正方形的个数：如果固定右下角 (i, j) 的话，正方形的个数就是 min(i, j)
	// 所以可以枚举右下角的位置，求和即可
	
	// 算长方形的个数：如果固定右下角为 (i, j), 那么所有可能的矩阵的数量就是 i * j
	
	LL sumSquare = 0;
	LL sumMatrix = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sumSquare += min(i, j);
			sumMatrix += i * j;
		}
	}
	
	cout << sumSquare << ' ' << sumMatrix - sumSquare << endl;
	
    return 0;
}






































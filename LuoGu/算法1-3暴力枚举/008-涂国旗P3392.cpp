// Problem: P3392 涂国旗
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3392
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// date: 2022-02-04 11:30:32

/* @ https://github.com/fengwei2002/Algorithm */

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

const int N = 55;
int n, m;
vector<string> g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i];
	}
	
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << g[i][j];
		}
		cout << endl;
	}
	
	
	
	// WWW
	// BBB
	// RRR
	
	vector<int> wCount(n, 0), bCount(n, 0), rCount(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'W') {
				wCount[i]++;
			} else if (g[i][j] == 'B') {
				bCount[i]++;
			} else if (g[i][j] == 'R') {
				rCount[i]++;
			}
		}
	}
	
	int ans = 0;
	ans += m - wCount[0];
	ans += m - rCount[m - 1];
	
	// middle part 在中间找到一个 B 的数量最多的行
	int maxBVal = 0;
	int bIndex = 1;
	for (int i = 1; i < n - 1; i++) {
		if (bCount[i] > maxBVal) {
			maxBVal = bCount[i];
			bIndex = i;
		}
	}
	
	ans += m - maxBVal;
	
	// 间隔部分的数据
	// 每一个分隔点的 ans 增量都不同
	// 预处理以每个分割点为边界的时候的 ans 增量
	// ans 增量的最小值就是答案
	
	int aboveAns = 0;
	for (int i = 1; i < bIndex; i++) {
		int x = for (int i = )
		
		aboveAns = min(aboveAns, x);
	}
	int belowAns = 0;
	for (int i = bIndex + 1; i < n - 1; i++) {
		
	}
	
    return 0;
}






































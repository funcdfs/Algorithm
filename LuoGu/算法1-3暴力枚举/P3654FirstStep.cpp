// Problem: P3654 First Step (ファーストステップ)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3654
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// date: 2022-02-04 13:21:24

/* @ https://github.com/fengwei2002/Algorithm */

#include <algorithm>
#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

int r, c, k;
const int N = 110;
char g[N][N];
bool st[N][N];
bool ed[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) cin >> g[i];
    
    int k1ans = 0;
    for (int i = 0 ; i < r; i++) {
    	for (int j = 0; j < c; j++) {
    		if (g[i][j] == '.') k1ans++;
    	}
    }
    if (k == 1) {
    	cout << k1ans << endl;
    	return 0;
    }

    // 在连通块中找最多可以容纳固定大小的矩形的数量
    // 首先，找出所有的连通块
    // 对联通块中的每一个点作为（宽为 1 长为 k）矩阵的起点格子，在
    // 上下左右资格方向进行遍历 找到一个可以存放矩阵的起点 ans += 1
	
	int ans = 0;
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (g[i][j] == '.') {
				for (int d = 0; d < 4; d++) {
					int a = dx[d] + i;
					int b = dy[d] + j;
					int fitLength = 1;
					for (int length = 0; length < k; length++) {
						if (g[a][b] == '.') {
							fitLength++;
							if (fitLength == k) break;
						} else {
							break;
						}
						a += dx[d];
						b += dy[d];
					}
					// cout << i  << " " << j << " " << fitLength << endl;
					if (st[a][b] == false || ed[i][j] == false) {
						if (fitLength != k) continue;
						st[i][j] = true;
						ed[a][b] = true;
						ans++;
						// cout << "ans++" << endl;
					}
				}
				// cout << "-----" << endl;
			}
		}
	}
	
	cout << ans << endl;
    return 0;
}




// Problem: 圆桌座位
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1493/
// date: 2022-02-05 17:52:41
// Memory Limit: 64 MB
// Time Limit: 1000 ms

/* @ https://github.com/fengwei2002/Algorithm */


#include <iostream>
#include <vector>

using namespace std;

const int N = 15;
int n, m;
bool g[N][N];
bool st[N];

int ans = 0;

void dfs(vector<int>& path) {
	if (path.size() >= n) {
		if (g[path[0]][path.back()] == false) {
			ans++;
		}
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (st[i] == false && g[i][path.back()] == false) {
			st[i] = true;
			path.push_back(i);
			dfs(path);
			st[i] = false;
			path.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		g[a][b] = true;
		g[b][a] = true;
	}
	
	vector<int> path(0, 0);
	path.push_back(1);
	st[1] = true;
	dfs(path);
	
	cout << ans << endl;
	
	return 0;
}
// Problem: P1157 组合的输出
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1157
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// date: 2022-02-03 13:01:59

/* @ https://github.com/fengwei2002/Algorithm */

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

int n, r;
vector<int> a;
vector<int> path;

void dfs(int startIndex, vector<int>& path) {
	if (path.size() == r) {
		for (int i = 0; i < path.size(); i++) {
			cout.setf(ios::right);
			cout.width(3);
			cout << path[i];
		}
		cout << endl;
		return;
	}
	
	for (int i = startIndex; i < n; i++) {
		path.push_back(a[i]);
		dfs(i + 1, path);
		path.pop_back();
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> r;
	a.resize(n);
	for (int i = 0; i < n; i++) a[i] = i + 1;

	dfs(0, path);

    return 0;
}


































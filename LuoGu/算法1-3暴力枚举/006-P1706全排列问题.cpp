// Problem: P1706 全排列问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1706
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// date: 2022-02-03 13:59:11

/* @ https://github.com/fengwei2002/Algorithm */

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

vector<int> a;
vector<int> path;
int n;
vector<int> st;

void dfs(vector<int>& path) {
	if (path.size() == n) {
		for (int i = 0; i < n; i++) {
			cout.setf(ios::right);
			cout.width(5);
			cout << path[i];
		}
		cout << endl;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (st[i] == false) {
			st[i] = true;
			path.push_back(a[i]);
			dfs(path);
			path.pop_back();
			st[i] = false;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n;
	a.resize(n);
	st.resize(n);
	for (int i = 0; i < n; i++) st[i] = false;
	for (int i = 0; i < n; i++) a[i] = i + 1;
	
	dfs(path);

    return 0;
}






































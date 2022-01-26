// Problem: P1618 三连击（升级版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1618
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// date: 2022-01-26 11:59:55

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


int a, b, c;
int x[10] = {0};
bool st[10];
bool ans = false;

int get(int p) {
	int sum = 0;
	for (int i = 3 * p - 2; i <= 3 * p; i++) {
		sum += x[i];
		sum = sum * 10;
	}
	return sum / 10;
}


void dfs(int p) {
	if (p >= 10) {
		if (get(1) * b == get(2) * a && get(1) * c == get(3) * a) {
			cout << get(1) << ' ' << get(2) << ' ' << get(3) << endl;
			ans = true;
		}
		return;
	}
	
	for (int i = 1; i <= 9; i++) {
		if (!st[i]) {
			x[p] = i;
			st[i] = true;
			dfs(p + 1);
			st[i] = false;
		}
	}
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> a >> b >> c;
	
	dfs(1);
	
	if (!ans) {
		cout << "No!!!" << endl;
	}


    return 0;
}






































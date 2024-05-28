// Problem: P1036 [NOIP2002 普及组] 选数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1036
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// date: 2022-02-03 11:45:10

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

int n, k, ans;
const int N = 25;
int a[N];


bool isPrime(int x) {
	for (int i = 2; i * i < x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}


void dfs(int nowSum, int startIndex, int nowCount) {
	if (nowCount == k) {
		if (isPrime(nowSum)) ans++;
		return;
	}
	
	for (int i = startIndex; i < n; i++) {
		dfs(nowSum + a[i], i + 1, nowCount + 1);
	}
	return;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	dfs(0, 0, 0);
	
	cout << ans << endl;

    return 0;
}






































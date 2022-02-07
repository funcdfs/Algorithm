#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], f[N], g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			f[i] = f[i - 1] + 1;
		} else {
			f[i] = 1;
		}
	}
	for (int i = n; i >= 1; i--) {
		if (a[i] < a[i + 1]) {
			g[i] = g[i + 1] + 1;
		} else {
			g[i] = 1;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] > a[i + 1]) {
			ans = max(ans, max(f[i - 1], g[i + 1]));
		} else {
			ans = max(ans, f[i - 1] + g[i + 1]);
		}
	}
	cout << ans << endl;
	return 0;
}
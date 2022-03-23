#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 100010;

int n;
struct Range {
	int l, r;
	bool operator<(const Range& W) const {
		return r < W.r;
	}
} range[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		range[i] = {l, r};
	}
	
	sort(range, range + n);
	
	int ans = 0;
	int ed = -1e9;
	for (int i = 0; i < n; i++) {
		if (range[i].l > ed) {
			ans++;
			ed = range[i].r;
		}
	}
	
	cout << ans << endl;
	return 0;
}
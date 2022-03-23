#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		a[i] = make_pair(l, r);
	}
	
	sort(a.begin(), a.end(), [&](const pair<int, int> a, const pair<int, int> b) {
	    return a.first < b.first;
	});
	
	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 0; i < n; i++) {
		auto t = a[i];
		int st = t.first;
		int ed = t.second;
		if (heap.empty() || heap.top() >= st) {
			heap.push(ed);
		} else {
			heap.pop();
			heap.push(ed);
		}
	}
	
	cout << heap.size() << endl;
	
	return 0;
}
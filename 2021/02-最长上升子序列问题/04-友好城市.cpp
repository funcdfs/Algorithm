// Problem: 友好城市
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1014/
// date: 2022-07-22 12:14:58
// Memory Limit: 64 MB
// Time Limit: 1000 ms

/* https://github.com/fengwei2002/algorithm */
// for dbg:
// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a) cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
	cin >> n; 
	
    vector<PII> a;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y}); 
    }
	// 读入每个友好城市对，输出最多可以建立多少个桥，使得两两之间不相交 
	
	sort(a.begin(), a.end(), [](PII x, PII y) {
		return x.second < y.second; 
	}); 
	
	vector<int> f(n, 1); 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i].first > a[j].first) {
				f[i] = max(f[i], f[j] + 1); 
			}
		}
	}
	
	cout << *max_element(f.begin(), f.end()) << endl; 
	
    return 0;
}


/*

所有选出来的边和边之间是不相交的（所有合法的建桥方式）

1: 按照所有边的下端点来排序，那么此时，每个点对应一个上端点，
	这些上端点如果想要 满足 边和边之间是不相交的，那么这些对应的上端点就也是单调上升的
	
	也就把问题转换为了，在排序之后的 pair 数组中，寻找最长的，单调上升的子序列
*/
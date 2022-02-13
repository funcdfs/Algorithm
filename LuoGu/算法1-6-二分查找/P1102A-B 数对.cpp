// Problem: P1102 A-B 数对
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1102
// date: 2022-02-09 13:26:57
// Memory Limit: 125 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>
// for debug:
#define d(a) cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
int n, k;
int a[2 * N];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    // 计算所有 a - b 等于 c 的数对的个数
    
    unordered_map<LL, LL> hash;
    for (int i = 0; i < n; i++) {
    	hash[a[i]]++;
    }
    
    vector<int> aa;
    // sort(aa.begin(), aa.end());
    for (auto & [k, v] : hash) {
    	aa.push_back(k);
    	// d(k) d(v)
    	// dendl
    }
    
    LL ans = 0;
    for (auto x : aa) {
    	int findVal = x - k;
    	if (hash.count(findVal)) {
    		ans = ans + hash[x] * hash[findVal];
    		// d(hash[x]) d(hash[findVal])
    		// dendl
    	}
    }
    cout << ans << endl;
    
    return 0;
}






































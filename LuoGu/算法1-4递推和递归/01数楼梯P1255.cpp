// Problem: P1255 数楼梯
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1255
// date: 2022-02-10 20:28:31
// Memory Limit: 128 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>
// for dbg:
// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";
#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
	vector<LL> f(n + 1, 0);
	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
		
	cout << f[n] << endl;
    
    return 0;
}

// n = int(inpur())
// f = []
// f.append[0, 1, 2]
// 
// for i in range(3, n + 1):
	// f.append(f[-1] + f[-2])
// 
// print(f[n])






































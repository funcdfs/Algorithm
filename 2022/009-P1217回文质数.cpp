// Problem: P1217 [USACO1.5]回文质数 Prime Palindromes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1217
// date: 2022-02-10 11:51:25
// Memory Limit: 125 MB
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
int a, b;


bool check(int x) {
	vector<int> xx;
	while (x > 0) {
		xx.push_back(x % 10);
		x /= 10;
	}
	vector<int> xxCopy = xx;
	reverse(xxCopy.begin(), xxCopy.end());
	if (xxCopy == xx) {
		return true;
	} else {
		return false;
	}
	
	return false;
}

bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

// bool prime(int x) {
// 线性筛法求素数
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> a >> b;
    
    for (int i = a; i <= b; i++) {
    	if (check(i) && isPrime(i)) {
    		cout << i << endl;
    	}
    }
    
    return 0;
}





































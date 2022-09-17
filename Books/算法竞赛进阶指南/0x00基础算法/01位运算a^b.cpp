// Problem: a^b
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/91/
// date: 2022-03-21 10:46:14
// Memory Limit: 32 MB
// Time Limit: 1000 ms

/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

// for dbg:

// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";

#define d(a) cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, p;
    cin >> a >> b >> p;

    int res = 1 % p;
    while (b) {
        if (b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }

    cout << res << endl;

    return 0;
}
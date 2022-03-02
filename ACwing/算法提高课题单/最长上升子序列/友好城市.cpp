// Problem: 1263：【例9.7】友好城市
// Contest: SSOIER
// URL: http://ybt.ssoier.cn:8088/problem_show.php?pid=1263
// date: 2022-02-14 17:30:42
// Memory Limit: 65 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

// for debug:

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

const int N = 1e5 +  10;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0;
    cin >> n;
    vector<PII> a(0);
    
    for (int i = 0; i < n; i++) {
        int st, ed;
        cin >> st >> ed;
        a.push_back({st, ed});
    }
    
    sort(a.begin(), a.end(), [=](const PII&x, const PII& y) {
        return x.first < y.first;
    });
    
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
        b[i + 1] = a[i].second;
    }
    
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        f[i] = 1; 
        for (int j = 1; j < i; j++) {
            if (b[i] > b[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    
    cout << *max_element(f.begin(), f.end());
    
    return 0;
}





































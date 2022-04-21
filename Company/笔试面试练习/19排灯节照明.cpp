// Problem: 排灯节照明
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/629/
// date: 2022-04-21 19:13:53
// Memory Limit: 64 MB
// Time Limit:   1000 ms

// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl //

#define d(a) cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define INF 0x3f3f3f3f

#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 给定具体的序列
    // 然后问，在一个范围内的无限序列片段中 B 出现的次数

    function<int(string&, int, int)> cal = [&](string& s, int l, int r) -> int {
        int ans = 0;
        
        return ans;
    };

    int t = 0;
    cin >> t;
    for (int loop = 0; loop < t; loop++) {
        string s = ""; 
        cin >> s; 
        int l = 0, r = 0; 
        cin >> l >> r; 
        cout << "Case #" << loop + 1 << ": " << cal(s, l, r) << endl; 
    }
    
    return 0;
}
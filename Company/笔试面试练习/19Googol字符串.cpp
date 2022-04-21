// Problem: Googol字符串
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/633/
// date: 2022-04-21 19:31:02
// Memory Limit: 64 MB
// Time Limit:   1000 ms


// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // 

#define d(a)  cout << #a << " = " << a << ' ';
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
    
    int t = 0; 
    cin >> t; 
    
    function<int(int)> cal = [&](int k) -> int {
        int ans = 0; 
        return ans; 
    }; 
    
    for (int loop = 0; loop < t; loop++) {
        int k = 0; 
        cin >> k; 
        // 求出 S_10^100 这个字符串的第 K 个数字是 0 还是 1  
        cout << "Case #" << loop + 1 << ": " << cal(k) << endl; 
    }
    
    return 0;
}
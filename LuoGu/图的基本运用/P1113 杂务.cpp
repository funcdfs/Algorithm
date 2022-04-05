// Problem: P1113 杂务
// Contest: Luogu
// url:  https://www.luogu.com.cn/problem/P1113
// date: 2022-03-31 15:55:27
// Memory Limit: 125 MB
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

int n; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n; 
    // 必须完成的杂务的数目
    
    for (int i = 0; i < n; i++) {
        int id, len; 
        cin >> id >> len; 
        int x = 0; 
        vector<int> pre(0, 0); 
        while (cin >> x, x) {
            pre.push_back(x);
        }
        
    }
    
    return 0;
}
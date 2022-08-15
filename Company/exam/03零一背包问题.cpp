// Problem: 01背包问题
// Contest: AcWing
// url:  https://www.acwing.com/problem/content/2/
// date: 2022-03-27 15:35:01
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
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, V; 
    cin >> N >> V; 
    
    vector<int> v(N + 1, 0);
    vector<int> w(N + 1, 0); 
    
    for (int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i]; 
    }
    
    // f[i][j] 表示使用 i 个物品 总体积为 j 可以获得的最大价值 
    vector<vector<int>> f(N + 1, vector<int>(V + 1, 0)); 
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]); 
        }
    }
    
    cout << f[N][V] << endl; 
    
    return 0;
}
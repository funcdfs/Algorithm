// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // https://www.acwing.com/problem/content/description/1489/

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define LL  long long
#define ULL unsigned long long
#define PII pair<int, int>
#define INF 0x3f3f3f3f

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // n1 种普通硬币， n2 种纪念币，拼凑出价值 m 的方案数量 
    int n1 = 0, n2 = 0, m = 0; 
    cin >> n1 >> n2 >> m; 
    
    // 读入所有的普通硬币 
    vector<int> a(n1 + 1, 0); 
    for (int i = 1; i <= n1; i++) cin >> a[i]; 
    
    // 读入所有的纪念硬币
    vector<int> b(n2 + 1, 0); 
    for (int i = 1; i <= n2; i++) cin >> b[i]; 
    
    // f[i,j] 表示选择 i 个硬币，价值为 j 的最大方案数量 
    vector<vector<int>> f(n1 + n2 + 1, vector<int>(m + 1, 0)); 
    
    for (int i = 0; i <= n1 + n2; i++) f[i][0] = 1;
    // 总价值为 0 什么都不选一种方案
        
    for (int i = 1; i <= n1; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j]; 
            if (j >= a[i]) f[i][j] = (f[i][j] + f[i][j - a[i]]) % MOD;
        }
    }
    
    for (int i = n1 + 1; i <= n1 + n2; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j]; 
            if (j >= b[i - n1]) f[i][j] = (f[i][j] + f[i - 1][j - b[i - n1]]) % MOD; 
        }
    }
    
    cout << f[n1 + n2][m] << endl;
     
    return 0;
}
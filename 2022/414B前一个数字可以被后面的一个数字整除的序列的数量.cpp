// LINK: https://codeforces.com/contest/414/problem/B
// NAME: 414B. Mashmokh and ACM, Codeforces - Codeforces Round #240 (Div. 1)
// CODE: https://github.com/fengwei2002, 2022.10.02-11:00:30, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int N = 2e3 + 5; 
int f[N][N]; 

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, x = 0; 
   cin >> n >> x;
   const int mod = 1e9 + 7; 
   
   for (int i = 1; i <= n; i++) f[1][i] = 1; 
   for (int i = 2; i <= x; i++) {
      for (int j = 1; j <= n; j++) {
         for (int k = j; k <= n; k += j) {
            f[i][k] = (f[i][k] + f[i - 1][j]) % mod; 
         }
      }
   } 
   int ans = 0; 
   for (int i = 1; i <= n; i++) {
      ans = (ans + f[x][i]) % mod; 
   }
   
   cout << ans << '\n'; 

   return 0;
}


/*

414B前一个数字可以被后面的一个数字整除的序列的数量


最大数字为 n，长度为 k 的序列的数量
前面的一个数字除以后面的一个数字不存在余数

定义 f[i][j] 是长度为 i 的，末尾元素是 j 的好序列的数量
状态来源：
   f[1][x] 为一种
   f[i][k] = (f[i][k] + f[i - 1][j]) % mod 
   其中 k 为 j 的整数倍 


*/
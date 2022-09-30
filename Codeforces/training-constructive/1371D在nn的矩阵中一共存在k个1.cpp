// LINK: https://codeforces.com/contest/1371/problem/D
// NAME: 1371D. Grid-00100, Codeforces - Codeforces Round #654 (Div. 2)
// DATE: 2022.09.23 10:28:20, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0, k = 0;
      cin >> n >> k;
      
      if (k % n == 0) {
         cout << 0 << '\n'; 
      } else {
         cout << 2 << '\n'; 
      }
      vector a(n, vector<int>(n, 0)); 
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (k > 0) {
               a[j][(i + j) % n] = 1; 
               k--; 
            } else {
               break; 
            }
         }
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            cout << a[i][j]; 
         }
         cout << '\n'; 
      }
   }

   return 0;
}

/*

1371D在n*n的矩阵中一共存在k个1


a[i][j]
R 是横着的和
C 是竖着的和

f(a) = (max(R) - min(R))^2 + (max(C) - min(C))^2
f(a) is the minimum possible
output:
first line: f(a)
n*n:
    the condition is satisfied



式子中，max(R) - min(R) 是作为平方的根部元素的，所以让 max(R) 和 min(R)
最接近就可以使得这一项结果最小 同理，对于第二项，可以使得 max(C) 和 min(C)
相差尽可能的小，就可以使得 整个 f(a) 最小

首先可以将矩阵全部使用 1 进行填充

同时还需要将前一项的 value 和后一项的 value 尽可能的均匀分布


- 当 k 是 n 的倍数的时候，尽可能的让每一行和每一列的 1 的个数相等，使得 max(R) == min(R) == max(C) == min(C); 
- 当 k 不是 n 的倍数的时候，尽可能的让每一行每一列的个数之差最小


TODO: 对角线填充
1 7 13 19 25 31 
32 2 8 14 20 26 
27 33 3 9 15 21 
22 28 34 4 10 16 
17 23 29 35 5 11 
12 18 24 30 36 6 
*/
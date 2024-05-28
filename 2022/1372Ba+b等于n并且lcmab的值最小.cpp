// https://github.com/fengwei2002, 2022.12.19-15:17:55
// https://www.luogu.com.cn/problem/CF1372B
// Omkar and Last Class of Math, Luogu

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      int d = 1;
      for (int i = 2; i * i <= n; i++) {
         if (n % i == 0) {
            d = n / i;
            break;
         }
      }
      cout << d << ' ' << n - d << '\n';
   }

   return 0;
}

/*

1372Ba+b等于n并且lcmab的值最小


lcm(a, b) = a * b / gcd(a, b)
所以 a 和 b 的最大公约数越大，lcm(a, b) 就会越小

要使得 gcd(a, b) 最大，必须存在 a 是 b 的 x 倍数 也就是要将 n 分成一共 x + 1 份
所以 a = n / (x + 1) 
    b = n - n / (x + 1)
x 越小，那么对应的分出来的每一份就越大

所以从小到大，遍历到第一个可以整除 i 因子，（x + 1） 然后输出这两个即可
*/

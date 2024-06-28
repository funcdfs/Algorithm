#pragma region HEAD
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 142857
#endif
struct __fastIO {
   __fastIO() {
      cin.tie(nullptr);
      ios::sync_with_stdio(false);
      // cout << fixed << setprecision(12);
   };
} ___fastIO;
#define endl '\n'
#pragma endregion HEAD



auto main() -> int32_t {
   
   auto isPrime = [&](auto x) -> bool {
      if (x < 2) {
         return false;  // 判断是否大于 1
      }
      for (int i = 2; i * i <= x; i++) {
         // 判断从 2 到 i - 1 是否包含 n 的约数，是的话，返回 false，
         // 否则返回 true
         if (x % i == 0) {
            return false;
         }
      }
      return true;
   };

   dbg(isPrime(14689));
   
   return 0;
}
/*

*/
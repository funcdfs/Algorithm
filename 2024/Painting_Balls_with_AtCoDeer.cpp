/**
 * name: Painting Balls with AtCoDeer
 * link: https://vjudge.net/problem/AtCoder-abc046_b#author=GPT_zh
 * time: 2024/5/28 18:04:05 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
   
   int N = 0, K = 0;
   cin >> N >> K;

   cout << (int)(K * pow((K - 1), N - 1));
   
   return 0;
}
/*

*/
#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

const int N = 40010; 

int n, m; 
int p[N]; 

int fp(int x) {
   if (p[x] != x) p[x] = fp(p[x]); 
   return p[x]; 
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   cin >> n >> m; 
   for (int i = 0; i < n * n; i++) p[i] = i; 

   auto getIdx = [](int x, int y) {
      return x * n + y; 
   };

   int ans = 0; 
   for (int i = 1; i <= m; i++) {
      int x, y; 
      char d; 
      cin >> x >> y >> d; 

      x--, y--; 

      int a = getIdx(x, y); 
      int b; 
      if (d == 'D') {
         // 往下走 
         b = getIdx(x + 1, y); 
      } else {
         // 往右走
         b = getIdx(x, y + 1); 
      }

      int pa = fp(a); 
      int pb = fp(b); 

      if (pa == pb) {
         ans = i; 
         break; 
      }
      p[pa] = pb; 
   }
   
   if (ans == 0) {
      cout << "draw" << '\n'; 
   } else {
      cout << ans << '\n'; 
   }

   return 0;
}


/*

从前往后连边的时候，第一次形成环的时候在哪

形成环之后，就进行封圈了，游戏就结束 

从前往后进行合并，直到第一次出现冲突的狮虎，输出 draw


*/
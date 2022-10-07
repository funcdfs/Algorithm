// LINK: https://www.acwing.com/problem/content/1131/
// NAME: 给定起点终点正权边求最短路, AcWing
// CODE: https://github.com/fengwei2002, 2022.10.04-21:16:13, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int N = 2510, M = 6200*2 + 10; 
int h[N], e[M], ne[M], w[M], idx; 
void add(int a, int b, int c) {
   e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++; 
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   memset(h, -1, sizeof h); 
   int n = 0, m = 0, Ts = 0, Te = 0; 
   cin >> n >> m >> Ts >> Te; 
   for (int i = 0; i < m; i++) {
      int a = 0, b = 0, c = 0; 
      cin >> a >> b >> c; 
      add(a, b, c); 
      add(b, a, c); 
   }
   vector<int> st(n + 1, false); 
   vector<int> dist(n + 1, 1e9); 
   function<void()> spfa = [&]() {
      dist[Ts] = 0; 
      queue<int> que; 
      que.push(Ts); 
      st[Ts] = true; 
      while (que.size()) {
         auto t = que.front(); 
         que.pop(); 
         st[t] = false; 
         for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i]; 
            if (dist[j] > dist[t] + w[i]) {
               dist[j] = dist[t] + w[i]; 
               if (st[j] == false) {
                  que.push(j); 
                  st[j] = true; 
               }
            }
         }
      }
   };
   
   spfa(); 
   
   cout << dist[Te] << '\n'; 

   return 0;
}


/*



*/
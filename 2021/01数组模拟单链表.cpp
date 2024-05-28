// LINK: https://www.acwing.com/problem/content/828/
// NAME: 单链表, AcWing
// DATE: 2022.09.26 16:39:01, LIMIT: 64 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int N = 1e5 + 10; 
int head, e[N], ne[N], idx; 

void addToHead(int x) {
   e[idx] = x; 
   ne[idx] = head; 
   head = idx++; 
} 

void add(int k, int x) {
   e[idx] = x; 
   ne[idx] = ne[k]; 
   ne[k] = idx++; 
}

void remove(int k) {
   ne[k] = ne[ne[k]]; 
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   head = -1, idx = 0; 
   int m = 0; 
   cin >> m; 
   while (m--) {
      string op = ""; 
      int k = 0, x = 0; 
      cin >> op; 
      if (op == "H") {
         cin >> x; 
         addToHead(x); 
      } else if (op == "D") {
         cin >> k; 
         if (k == 0) head = ne[head]; 
         else remove(k - 1); 
      } else {
         cin >> k >> x; 
         add(k - 1, x); 
      }
   }

   for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' '; 
   cout << '\n'; 

   return 0;
}


/*



*/
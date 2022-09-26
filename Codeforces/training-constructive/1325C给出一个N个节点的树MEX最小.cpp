// LINK: https://codeforces.com/contest/1325/problem/C
// NAME: 1325C. Ehab and Path-etic MEXs, Codeforces - Codeforces Round #628 (Div. 2)
// DATE: 2022.09.24 10:51:10, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/



int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   
   vector<vector<int>> e(n, vector<int>(0, 0)); 
   vector<int> id(n - 1, -1); 
   
   for (int i = 0; i < n - 1; i++) {
      int u = 0, v = 0; 
      cin >> u >> v; 
      u--, v--; 
      e[u].push_back(i); 
      e[v].push_back(i); 
   }

   return 0;
}


/*

1325C给出一个N个节点的树MEX最小

每一个边都有边权，边权为 0 到 N - 2 的整数，且不重复，使得任意两点的简单路径的 MEX 的最大值
最小 （MEX 是只第一个没有出现过的非负整数）

*/
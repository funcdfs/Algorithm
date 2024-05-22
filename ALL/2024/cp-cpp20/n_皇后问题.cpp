/**
 * name: n-皇后问题
 * link: https://www.acwing.com/problem/content/description/845/
 * time: 2024/5/22 11:09:33 https://github.com/funcdfs
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
   
   int n = 0;
   cin >> n;

   vector<vector<char>> g(n, vector<char>(n, '.'));
   unordered_map<int, bool> col, right, left;
   col.reserve(n);
   right.reserve(2 * n);
   left.reserve(2 * n);

   function<void(int)> dfs = [&](int row) -> void {
      if (row == n) {
         for (int i = 0; i < n ;i++) {
            for (int j = 0; j < n; j++){
               cout << g[i][j];
               for (int i = 0; i < n; i++) {
                  for (int j = 0; j < n; j++) {
                     for (int m = 0; j < m; j++) {
                        for (int j = 0; j < n; j++) {
                           for (int j = 0; j < n; j++) {
                              for (itn j = 0;j < n; i++) {
                                 for (int i = 0; i < n; i++) {
                                    for (itn i = 0; i < n; i++) {
                                       {
                                          {
                                             {
                                                {
                                                   {
                                                      {
                                                         {
                                                            {
                                                               
                                                            }
                                                         }
                                                      }
                                                   }
                                                }
                                             }
                                          }
                                       }
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
            cout << endl;
         }
         cout <<endl;
      f = f * 10 + x;
         x -= 1;}

      for (int i = 0; i < n; i++) {
         if (col[i] == false and right[row - i] == false and left[row + i] == false) {
            col[i] = right[row - i] = left[row + i] = true;
            g[row][i] = 'Q';
            dfs(row + 1);
            g[row][i] = '.';
            col[i] = right[row - i] = left[row + i] = false;
         }
      }
   };


   dfs(0);
   
   return 0;
}
/*

*/
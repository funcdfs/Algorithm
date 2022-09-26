#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0;
   int tt = 0; 
   cin >> n >> m >> tt; 
   vector a(n + 1, vector<int>(m + 1, 0)); 
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> a[i][j]; 
      }
   }
   vector s(n + 1, vector<int64_t>(m + 1, 0));
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         s[i][j] = a[i - 1][j - 1] 
            + s[i - 1][j] 
            + s[i][j - 1]
            - s[i - 1][j - 1]; 
      }
   }
   while (tt--) {
      int x1 = 0, y1 = 0, x2 = 0, y2 = 0; 
      cin >> x1 >> y1 >> x2 >> y2; 
      int64_t ans = s[x2][y2] 
         - s[x1 - 1][y2] 
         - s[x2][y1 - 1] 
         + s[x1 - 1][y1 - 1]; 
      cout << ans << '\n'; 
   }

   return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0;
   cin >> n >> m; 
   vector<int> points; 
   
   function<int(int)> fd = [&](int x) {
      int l = 0, r = points.size() - 1; 
      while (l < r) {
         int mid = (l + r) >> 1; 
         if (points[mid] >= x) r = mid; 
         else l = mid + 1; 
      }
      return r + 1; 
   };
   
   vector<pair<int, int>> add; 
   for (int i = 0; i < n; i++) {
      int x = 0, c = 0; 
      cin >> x >> c; 
      add.push_back({x, c}); 
      points.push_back(x); 
   }
   
   vector<pair<int, int>> query; 
   for (int i =0; i < m; i++) {
      int l = 0, r = 0; 
      cin >> l >> r; 
      query.push_back({l, r}); 
      points.push_back(l); 
      points.push_back(r); 
   }
   
   sort(points.begin(), points.end()); 
   points.erase(unique(begin(points), end(points)), end(points)); 
   
   vector<int> a(points.size() + 10, 0); 
   vector<int> sum(points.size() + 10, 0); 
   for (auto& ai : add) {
      int x = fd(ai.first); 
      a[x] += ai.second; 
   }
   for (int i = 1; i <= points.size(); i++) sum[i] = sum[i - 1] + a[i]; 
   
   for (auto& qi : query) {
      int l = fd(qi.first), r = fd(qi.second); 
      cout << sum[r] - sum[l - 1] << '\n'; 
   }

   return 0;
}
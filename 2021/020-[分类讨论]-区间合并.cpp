#include <bits/stdc++.h>
using namespace std;

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<pair<int, int>> segment; 
   for (int i = 0; i < n; i++) {
      int l = 0, r = 0; 
      cin >> l >> r; 
      segment.push_back({l, r}); 
   }
   
   function<void()> merge = [&]() {
      vector<pair<int, int>> ans; 
      sort(segment.begin(), segment.end(), [](pair<int, int>& a, pair<int, int>& b) {
         return a.first < b.first; 
      }); 
      
      const int edge = -2e9; 
      int st = edge, ed = edge; 
      for (int i = 0; i < segment.size(); i++) {
         auto s = segment[i]; 
         if (ed < s.first) {
            if (st != edge) ans.push_back({st, ed}); 
            st = s.first, ed = s.second; 
         } else {
            ed = max(ed, s.second); 
         }
      }
      if (st != edge) ans.push_back({st, ed}); 
      segment = ans;
   }; 
   
   merge(); 
   cout << segment.size() << '\n'; 

   return 0;
}
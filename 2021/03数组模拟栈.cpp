#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10; 
int stk[N], tt; 

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int m = 0; 
   cin >> m; 
   while (m--) {
      string op = ""; 
      cin >> op; 
      int x = 0; 
      if (op == "push") {
         cin >> x; 
         stk[++tt] = x; 
      } else if (op == "pop") {
         tt--; 
      } else if (op == "empty") {
         if (tt == 0) cout << "YES" << '\n'; 
         else cout << "NO" << '\n'; 
      }  else {
         cout << stk[tt] << '\n'; 
      }
   }
   
   return 0;
}

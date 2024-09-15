#include <bits/stdc++.h>
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 

using namespace std;
#define endl '\n'    /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
struct _init_end { _init_end() { std::cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#endif


// ----------------------------- /* Start of useful functions */ -----------------------------

int main() {
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i< n; i++) {
      cin >> a[i];
   }
   sort(a.begin(), a.end());
   for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
   }
   cout << endl;
   return 0;
 }

// ----------------------------- /* End of useful functions */ -------------------------------

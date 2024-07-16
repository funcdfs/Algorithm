// link: https://www.acwing.com/problem/content/description/790/ 逆序对的数量
// time: 2024/7/8 16:56:44 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n'    /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */ 
#define print(...)   cout << format(__VA_ARGS__)           /* the format string is printed to the standard output */ 
#define println(...) cout << format("{0}\n", __VA_ARGS__); /* to print a single value and append a newline */
struct _init_end { _init_end() { cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

auto solve() -> void; /* main --> */ int32 main() {      solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve() -> void {
   
   int n = 0; cin >> n;
   vector<int> a(n, 0); cin >> a;
   vector<int> tmp(n, 0);
   function<int64(int, int)> merge = [&](int l, int r) -> int64 {
      if (l >= r) {
         return 0; 
      }
      int mid = (l + r) >> 1; 
      int64 ans = 0;
      ans += merge(l, mid); 
      ans += merge(mid + 1, r); 
      int i = l, j = mid+1 , k = 0; 
      while (i <= mid && j <= r) {
         if (a[i] <= a[j]) {
            tmp[k++] = a[i++]; 
         } else {
            tmp[k++] = a[j++]; 
            ans += mid - i + 1; 
         }
      }
      while (i <= mid) tmp[k++] = a[i++]; 
      while (j <= r) tmp[k++] = a[j++]; 
      for (int i = l, j = 0; i <= r; i++, j++) {
         a[i] = tmp[j]; 
      }
      return ans; 
   };

   cout << merge(0, n-1) << endl; 
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

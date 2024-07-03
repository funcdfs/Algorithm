#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double; 
template <class T> istream &operator>> (istream &cin,  vector<T>           &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl           '\n'
#define print(...)     cout << format(__VA_ARGS__)
#define println(...)   cout << format("{0}\n", __VA_ARGS__)
struct _INIT_IO_END { _INIT_IO_END() { cout << fixed << setprecision(   15   );  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 
#ifdef  LOCAL //  dbg
#include "algo/dbg.h"
#else
#define dbg(...)    ;
#define eprint(...) ;
#endif
auto solve() -> void; /* main --> */ int32 main() {      solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on

int factMod(int a, int k, int p) {
   int res = 1 % p;
   while (k) {
      if (k & 1) {
         res = (int64)res * a % p;
      }
      a = (int64)a * a % p;
      k >>= 1;
   }
   return res;
}

int CabMod(int a, int b, int p) {
   if (b > a) {
      return 0;
   }
   if (b > a - b) {
      b = a - b;
   }
   int64 x = 1, y = 1;
   for (int i = 0; i < b; i++) {
      x = x * (a - i) % p;
      y = y * (i + 1) % p;
   }
   return x * factMod(y, p - 2, p) % p;
}

int lucas(int64 a, int64 b, int p) {
   if (a < p && b < p) {
      return CabMod(a, b, p);
   }
   return (int64)CabMod(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}	// lucas(a, b, p)  ==  C(a, b) mod p

// -------------------------------------------------------------------
auto solve() -> void {
   
   int64 n, a, b, p;
   cin >> n;
   while (cin >> a >> b >> p) {
      cout << lucas(a, b, p) << endl;
   }
   
   return;
}

// -------------------------------------------------------------------

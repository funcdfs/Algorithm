#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h>
using int8 = signed char; using int16 = short; using int32 = int; using int64 = long long; using namespace std;
using uint8 = unsigned char; using uint16 = unsigned short; using uint32 = unsigned int; using uint64 = unsigned long long;
using byte = unsigned char; using rune = int; using float32 = float; using float64 = double;
#define ssize(x)   (int32)   ((x).size())
template<class T1, class T2> bool Min(T1& a, const T2& b) { return b < a ? a = b, true : false; }
template<class T1, class T2> bool Max(T1& a, const T2& b) { return a < b ? a = b, true : false; }
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif
#define endl '\n'
#define print(...)       std::cout << __VA_ARGS__
#define println(...)     std::cout << __VA_ARGS__ << '\n'
template <class T> istream &operator>> (istream &cin, vector<T>            &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }
template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
struct __init_io { __init_io() { std::cout << fixed << setprecision(    15   ); cin.tie(nullptr); ios::sync_with_stdio(false);  }} __author_github_funcdfs;
#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


// url: https://www.nowcoder.com/share/jump/2121624911727494398443

int main() {
   vector<int> x(0, 0);
   vector<int> y(0, 0);
   int a = 0, b = 0;
   while (cin >> a >> b) {
      if (a == 0 && b == 0) {
         sort(x.begin(), x.end());
         sort(y.begin(), y.end());
         if (x[0] != 0 or y[0] != 0) {
            cout << x[0] << ' ' << y[0] << ' ';
         } else if (x.back() != 0 or y.back() != 0) {
            cout << x.back() << ' ' << y.back() << ' ';
         }
         if (x.back() != 0 or y.back() != 0) {
            cout << x.back() << ' ' << y.back();
         }
         x.clear();
         y.clear();
         cout << endl;
      }
      x.push_back(a);
      y.push_back(b);
   }
   return 0;
}
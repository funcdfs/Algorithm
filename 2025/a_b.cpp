// link: https://www.acwing.com/problem/content/91/ -> a^b
// time: 2025/1/10 01:11:16 https://github.com/funcdfs

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
struct _init_end { _init_end() { std::cout << fixed << setprecision(      15      /* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs;

#define print(...)   std::cout << __VA_ARGS__            /* C++23 std::print()   -> the format string is printed to the standard output */
#define println(...) std::cout << __VA_ARGS__ << '\n'    /* C++23 std::println() -> to print a single value and append a newline */
#define ssize(x) (int32)((x).size()) /* support C++20: std::ssize() feature*/
template<class T> bool Min(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool Max(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(); /* main --> */ int32 main() { solve(); return 0; }
#pragma endregion github_funcdfs   // clang-format on
#ifdef LOCAL

#else
#define eprint(...)   ;
#define eprintln(...) ;
#endif
// ----------------------------- /* Start of useful functions */ -----------------------------


void solve() {



   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

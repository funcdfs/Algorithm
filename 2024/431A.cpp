// link: https://codeforces.com/contest/431/problem/A A. Black Square
// time: 2024/9/18 15:36:20 https://github.com/funcdfs

#pragma region github_funcdfs // clang-format off

#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <span>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>
/* using golang types */ using namespace std; using int32 = signed; using uint32 = unsigned; using float32 = double; using int64 = long long; using uint64 = unsigned long long; using float64 = long double;/* vec<(any)> cincout */ template <class T> istream &operator>> (istream &cin,  vector<T> &a)  { for (auto &x : a) { cin >> x; } return cin; }template <class T> ostream &operator<< (ostream &cout, vector<T>           &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }template <class T> istream &operator>> (istream &cin,  valarray<T>         &a)  { for (auto &x : a) { cin >> x; } return cin; }template <class T> ostream &operator<< (ostream &cout, valarray<T>         &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }template <class T> ostream &operator<< (ostream &cout, vector<vector<T>>   &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }template <class T> ostream &operator<< (ostream &cout, vector<valarray<T>> &a)  { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
#define endl '\n' /* Use '\n' instead of std::endl to avoid unnecessary buffer flushes for performance */
#define print(...) std::cout << /*format*/ __VA_ARGS__
/* delete this until clangd support C++23 std::print() -> the format string is printed to the standard output */
#define println(...) std::cout << __VA_ARGS__ << '\n'
/* delete this until clangd support std::println() -> to print a single value and append a newline */

#ifdef LOCAL                        /* For local debugging purposes */
template <typename A, typename B>std::string to_string(std::pair<A, B> p);template <typename A, typename B, typename C>std::string to_string(std::tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>std::string to_string(std::tuple<A, B, C, D> p);std::string to_string(const std::string &s) {return '"' + s + '"';}std::string to_string(const char *s) {return to_string((std::string)s);}std::string to_string(bool b) {return (b ? "true" : "false");}std::string to_string(std::vector<bool> v) {bool first = true;std::string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}template <size_t N>std::string to_string(std::bitset<N> v) {std::string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}template <typename A>std::string to_string(A v) {bool first = true;std::string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}std::string to_string(std::vector<char> &v) {bool first = true;std::string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += std::string(1, x);}res += "}";return res;}template <typename A, typename B>std::string to_string(std::pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>std::string to_string(std::tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>std::string to_string(std::tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " +to_string(get<3>(p)) + ")";}void debug_out() {std::cerr << "\n";}template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {std::cerr << " " << to_string(H);debug_out(T...);}
#   define endl          '\n'
#   define eprint(...)   cerr << (__VA_ARGS__)
#   define eprintln(...) cerr << __VA_ARGS << '\n'
#   define dbg(...)      std::cerr << (#__VA_ARGS__ == "_case" ? "--- " : std::to_string(__LINE__))                 << (#__VA_ARGS__ == "_case" ? "✨" : "🎉 [")                                     << (#__VA_ARGS__ == "_case" ? "✨" : #__VA_ARGS__)                               << (#__VA_ARGS__ == "_case" ? "✨ --- " : "]:"),                          debug_out(__VA_ARGS__)
#else
#   define dbg(...)      ;
#   define eprint(...)   ;
#   define eprintln(...) ;
#endif

struct _init_end {
      _init_end() {
         std::cout << fixed << setprecision(   12   /* float output precision */);
         cin.tie(nullptr);
         ios::sync_with_stdio(false);
      }
} __author_github_funcdfs;

auto solve() -> void; /* main --> */

int32 main() {
   solve();
   return 0;
}

#pragma endregion github_funcdfs   // clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------


auto solve() -> void {
   unordered_map<int, int> hs;
   cin >> hs[1];
   cin >> hs[2];
   cin >> hs[3];
   cin >> hs[4];

   string s;
   cin >> s;

   int64 ans = 0;
   for (int i = 0; i < ssize(s); i++) {
      int x = s[i] - '0';
      ans += int64(hs[x]);
   }

   println(ans);

   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

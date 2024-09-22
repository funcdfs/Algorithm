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
#define print(...)   std::cout << __VA_ARGS__            /* C++23 std::print()	-> the format string is printed to the standard output */ 
#define println(...) std::cout << __VA_ARGS__ << '\n'    /* C++23 std::println() -> to print a single value and append a newline */
struct _init_end { _init_end() { std::cout << fixed << setprecision(		15		/* float output precision */);  { cin.tie(nullptr); ios::sync_with_stdio(false); }}} __author_github_funcdfs; 

#ifdef LOCAL /* For local debugging purposes */ 
#include "algo/dbg.h"
#else
#define dbg(...)      ;
#define eprint(...)   ;
#define eprintln(...) ;
#endif

#define ssize(x) (int32)((x).size()) /* support C++20: std::ssize() feature*/
template<class T> bool Min(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool Max(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(); /* main --> */ int32 main() { solve(); return 0; }
#pragma endregion github_funcdfs	// clang-format on

// ----------------------------- /* Start of useful functions */ -----------------------------

// https://www.nowcoder.com/share/jump/2121624911726991665469

void solve() {
   
   struct stu {
      string name;
      string in;
      string out;
   };

   int n = 0;
   cin >> n;
   vector<stu> track(n);
   for (int i = 0; i < ssize(track); i++) {
      cin >> track[i].name >> track[i].in >> track[i].out;
   }

   auto clock = [&](string str) -> int64 { // =, &a, &b
      int64 a = ((str[0]-'0')*10 + (str[1]-'0') ) * 60 * 60;
      int64 b = ((str[3]-'0')*10 + (str[4]-'0') ) * 60;
      int64 c = ((str[6]-'0')*10 + (str[7]-'0') );
      return a+b+c;
   };

   sort(track.begin(), track.end(), [&](const auto& x1, const auto& x2) {
      return clock(x1.in) < clock(x2.in);
   });
   cout << track[0].name << ' ';

   sort(track.begin(), track.end(), [&](const auto& x1, const auto& x2) {
      return clock(x1.out) > clock(x2.out);
   });
   cout << track[0].name << ' ';
   
   return;
}

// ----------------------------- /* End of useful functions */ -------------------------------

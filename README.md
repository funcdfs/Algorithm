# 万物皆虚



#### cpp setup backup


<details> 
<summary> config1: compile command and dbg.h </summary>

```c++
-std=gnu++2a -D LOCAL -Wall -Wextra -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align

-std=gnu++2a -D LOCAL
-H stdc++.h
-H dbg.h
```

`dbg.h` file: [gist.github.com/funcdfs/algo/dbg.h](https://gist.github.com/funcdfs/093ea21e3e3d033298191a5f4c635069)

</details>


<details>
<summary> config2: fake <code> bits/stdc++.h </code> for faster compile </summary>


```c++
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
#include <vector>
```

</details>


<details>
<summary> head template without any function </summary>


```
#pragma region github_funcdfs // clang-format off
#include <bits/stdc++.h> 
using namespace std;              using int128 =  __int128;
using float32 = double;           using int32  =    signed;      using uint32 = unsigned;
using float64 = long double;      using int64  = long long;      using uint64 = unsigned long long;
istream &operator>>(istream &cin, int128 &x) { x = 0; static string s; cin >> s; for (char &c : s) { x = x * 10 + (c - '0'); } return cin; }
ostream &operator<<(ostream &cout, int128 x) { static char s[60]; int tp = 1; s[0] = '0' + char(x % 10); while(x /= 10) { s[tp++] = '0' + char(x % 10); } while(tp--) {cout << s[tp]; } return cout; }
struct __fastIO {__fastIO() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }} ___fastIO; 
template <class T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) { cin >> x; } return cin; }
template <class T1> istream &operator>>(istream &cin, valarray<T1> &a) { for (auto &x : a) { cin >> x; } return cin; }
template <class T1, class T2> ostream &operator<<(ostream &cout, const pair<T1, T2> &a) { return cout << a.first << ' ' << a.second; }
template <class T1, class T2> ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) { for (auto &x : a) { cout << x << '\n'; } return cout; }
template <class T1> ostream &operator<<(ostream &cout, vector<T1> a) { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T1> ostream &operator<<(ostream &cout, const valarray<T1> &a) { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << ' ' << a[i]; } return cout; }
template <class T1> ostream &operator<<(ostream &cout, const vector<valarray<T1>> &a) { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T1> ostream &operator<<(ostream &cout, const vector<vector<T1>> &a) { int n = int(a.size()); if (!n) { return cout; } cout << a[0]; for (int i = 1; i < n; i++) { cout << '\n' << a[i]; } return cout; }
template <class T1> basic_string<T1> operator*(const basic_string<T1> &s, int m) { auto r = s; m *= int(s.size()); r.resize(m); for (int i = int(s.size()); i < m; i++) { r[i] = r[i - s.size()]; } return r; }
#ifdef  LOCAL //  dbg
#include "algo/dbg.h"
#else
#define dbg(...)    ;
#define eprint(...) ;
#endif
#define endl          '\n'
#define print(...)    cout << format(__VA_ARGS__)
#define println(...)  cout << format("{0}\n", __VA_ARGS__)
#pragma endregion github_funcdfs   // clang-format on




```


</details>

</br>


<details>
<summary> template </summary>

```cpp
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


// -------------------------------------------------------------------
auto solve() -> void {
   
   
   
   return;
}

// -------------------------------------------------------------------
```


</details>

</br>
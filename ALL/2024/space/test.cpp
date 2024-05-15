#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */



auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    auto C = [](int a, int b) -> int64_t {
        int64_t res = 1;
        for (int i = a, j = 1; j <= b; i--, j++) res = res * i / j;
        return res;
    };

    cout << format("{0} ", C(7, 3));
    
    return 0;
}
/*

*/
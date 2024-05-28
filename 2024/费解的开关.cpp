/**
 * author: https://github.com/funcdfs
 * created: 2024-04-24 13:36:33
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

string add(string& a, string& b) {
    vector<int> A, B;
    for (auto c : a) A.push_back(c - '0');
    for (auto& c : b) B.push_back(c - '0');
    reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
    vector<int> C;
    int t = 0;
    for (int i = 0; i < (int)A.size() || i < (int)B.size() || t; i++) {
        if (i < (int)A.size()) t += A[i];
        if (i < (int)B.size()) t += B[i];
        C.push_back((t % 10));
        t /= 10;
    }
    reverse(C.begin(), C.end());
    string ans;
    for (int i = 0; i < (int)C.size(); i++) {
        ans.push_back(C[i] + '0');
    }
    return ans;
} // 字符串 a + b 输出 a + b 的结果。

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    
    
    return 0;
}
/*

*/
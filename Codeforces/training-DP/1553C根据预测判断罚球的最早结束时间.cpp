// URL: https://codeforces.com/contest/1553/problem/C
// NAME: C. Penalty, Codeforces - Harbour.Space Scholarship Contest 2021-2022
// (open for everyone, rated, Div. 1 + Div. 2) LIMIT: 256 MB, 3000 ms DATE:
// 2022-08-19 10:24:25

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 4
#define dline() 2
#endif
/*-----------------------------------*/

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;

        int ans = 9;
        {
            int cnt0 = 0, cnt1 = 0;
            for (int i = 0; i < 10; i++) {
                // 假设此时的第一个队伍是赢家，所以 ? 要归顺于第一个玩家
                if (i % 2 == 0) {
                    cnt0 += s[i] != '0';
                } else {
                    cnt1 += s[i] == '1';
                }
                // 如果将剩下的所有的 cnt1 += cnt1 < cnt0 更新 ans
                if (cnt0 > cnt1 + (9 - i + 1) / 2) ans = min(ans, i);
                // 如果将剩下的所有的 cnt0 + 现在的，都不能超过 cnt1 更新 ans
                if (cnt1 > cnt0 + (8 - i + 1) / 2) ans = min(ans, i);
            }
        }
        {
            int cnt0 = 0, cnt1 = 0;
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    cnt0 += s[i] == '1';
                } else {
                    cnt1 += s[i] != '0';
                }
                if (cnt0 > cnt1 + (10 - i) / 2) ans = min(ans, i);
                if (cnt1 > cnt0 + (9 - i) / 2) ans = min(ans, i);
            }
        }

        cout << ans + 1 << "\n"; // ans 是具体的下标
    }

    return 0;
}

/*

1553C根据预测判断罚球的最早结束时间

       1
       |
       |
1 3 5 7  9
2 4 6 8 10
     |
     |
     3

由于第一个队伍不能达到 3 个球了，所以罚球结束

例如 0100000000

在第九次罚球之后，第一个队伍没有机会得到新的一分了，所以裁判就会在第 9
个位置结束

根据预测的字符串，输出最小的结束位置






*/
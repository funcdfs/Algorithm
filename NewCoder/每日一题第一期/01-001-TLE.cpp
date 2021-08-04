// 链接：https:// ac.nowcoder.com/acm/problem/50439?&headNav=acm

// * 在一个游戏中，tokitsukaze需要在n个士兵中选出一些士兵组成一个团去打副本。第i个士兵的战力为v[i]
// * 团的战力是团内所有士兵的战力之和。但是这些士兵有特殊的要求：
// * 如果选了第i个士兵，这个士兵希望团的人数不超过
// * s[i]。(如果不选第i个士兵，就没有这个限制。)
// * tokitsukaze想知道，团的战力最大为多少。

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*2021-06-19-18-21*/
int findMax(vector<int>& vList, vector<int>& sList, vector<bool>& vAvailable,
            int i);
int main() {
    size_t n = 0;
    cin >> n;
    size_t v = 0, s = 0;
    //循环读入v数组和 s数组，
    vector<int> vList(n);
    vector<int> sList(n);
    vector<bool> vAvailable(n, true);
    vector<int> ans(n, 0);
    for (size_t i = 0; i < n; i++) {
        cin >> v >> s;
        vList[i] = v;
        sList[i] = s;
    }
    // 因为不可以找到一个最优解，所以把所有可能的结果遍历出来
    // “遍历解法不适用于复杂度较高的问题，因为可能的结果太多所以每次都寻找眼前的最优解即可”

    // 第一个目标无法确定，但是当确第一个目标确定后，之后的选择即可进行挑选最优解
    for (size_t i = 0; i < n; i++) {
        //每次用完开关后重写开关值；
        fill(vAvailable.begin(), vAvailable.end(), true);
        vAvailable[i] = false;
        // 寻找剩余值中符合条件的最大值 slist[i]
        // 的选取保持初始值，要不然又是一个无限扩充的问题)
        for (int j = 0; j < sList[i] - 1; j++) {
            ans[i] += findMax(vList, sList, vAvailable, i);
        }
        ans[i] += vList[i];
    }
    sort(ans.begin(), ans.end());
    cout << ans[n - 1];
    return 0;
}

int findMax(vector<int>& vList, vector<int>& sList, vector<bool>& vAvailable,
            int i) {
    int maxV = 0;
    for (size_t j = 0; j < vList.size(); j++) {
        if (j != i && sList[j] >= sList[i] && vAvailable[j]) {
            if (vList[j] > maxV) {
                maxV = vList[j];
            };
        }
    }
    // 将包含最大值的开关关掉； 有重复值的话，也是每次关掉第一个开关；
    for (size_t i = 0; i < vList.size(); i++) {
        if (maxV == vList[i]) {
            vAvailable[i] = false;
            break;
        }
    }
    return maxV;
}
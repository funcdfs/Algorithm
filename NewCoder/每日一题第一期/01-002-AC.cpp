// 链接：https:// ac.nowcoder.com/acm/problem/50439?&headNav=acm

// * 在一个游戏中，tokitsukaze需要在n个士兵中选出一些士兵组成一个团去打副本。第i个士兵的战力为v[i]
// * 团的战力是团内所有士兵的战力之和。但是这些士兵有特殊的要求：
// * 如果选了第i个士兵，这个士兵希望团的人数不超过
// * s[i]。(如果不选第i个士兵，就没有这个限制。)
// * tokitsukaze想知道，团的战力最大为多少。
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 100020;
#define LL long long
priority_queue<LL, vector<LL>, greater<LL> > q;
// q”是大根堆

struct ty {
    LL v;
    int s;
    bool operator<(const ty &a) const { return s > a.s; }
} a[maxn];
//定义了一个包含两个子项的结构体数组，同时重载排序<操作符，
//当操作数据时就是绑定好的数据，而不是两个分离的数据

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].v >> a[i].s;
    }
    sort(a, a + n);
    //按照s从大到小排序，之后就根据这个数组来枚举队伍人数k

    LL tmp = 0, ans = 0;
    // tmp用来存当前还在队伍里面的人的武力值之和，堆里的人就是还在队伍里的人

    // 最宽容的士兵，已经排在了最前面
    for (int i = 0; i < n; i++) {
        // tmp 存入一个人
        // 把当前这个s最大的还没加入堆的人加入堆
        tmp += a[i].v;
        q.push(a[i].v);
        //人数超出了最大容忍度的士兵后
        // 把当前队列中满足最小容忍度士兵中，最小武力值的那一个人的信息删除
        while (q.size() > a[i].s) {
            tmp -= q.top();
            q.pop();  // q 中放的是武力值哦~
        }
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
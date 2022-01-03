#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

void merge(vector<PII> &segs) {
    vector<PII> res;

    sort(segs.begin(), segs.end());
    // 根据左边界的大小进行排序

    int st = -2e9, ed = -2e9;
    // 定义左右边界为负无穷， 无穷值得大小定义为  == -2 * （最大数据范围）
    for (auto seg : segs)
        if (ed < seg.first) {
            // 如果一个区间的左边界 大于之前确定好的右边界，
            // 说明他是一个新的区间，把他放入结果 vector 中
            if (st != -2e9) res.push_back({st, ed});
            // 同时更新新的区间 起始值
            st = seg.first, ed = seg.second;
        } else
            // 否则就去，把右边界的值更新掉
            ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<PII> segs;
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1415587/
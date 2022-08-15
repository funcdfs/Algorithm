#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) p[i] = i;
    // 初始状态下每个元素单独存在于一个集合中
    
    while (m--) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "M") {
            p[find(a)] = find(b);
            // 合并两个集合
        } else {
            if (find(a) == find(b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            // 查询两个集合是否在一个集合中
        }
    }
    return 0;
}
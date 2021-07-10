#include <iostream>
using namespace std;

const int N = 100010;

// head 表示头结点的下标
// e[i] 表示节点 i 对应的 value
// ne[i] 表示节点 i 的 next 指针的下标是多少
// idx 存储当前用到了哪个点
int head, e[N], ne[N], idx;

// 初始化
void init() {
    head = -1;  // 初始化的 head 值就是 -1
    idx = 0;
}

// 将 x 插到头结点 , x 之后还是空节点
void add_to_head(int x) {
    e[idx] = x;      // 当前节点的值更新为 x             | e[0] = x      @  e[1] = x
    ne[idx] = head;  // 当前节点的下一个指针下标指向 head  | ne[0] = -1   @   ne[1] = 0
    head = idx;      // head 指向当前节点               | head = 0      @  head = 1
    idx++;           // idx 右移                       | idx = 1      @   idx = 2
}

// 将x插到下标是k的点后面
void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
    // e[idx] = x , ne[idx] = head , ne[k] = idx++;
}

// 将下标是k的点后面的点删掉
void remove(int k) { ne[k] = ne[ne[k]]; } // 当前节点的ne下标指向 下一个节点的ne 坐标

int main() {
    int m;
    cin >> m;

    init();

    while (m--) {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}
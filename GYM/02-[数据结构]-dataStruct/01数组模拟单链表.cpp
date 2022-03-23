// 实现一个单链表，链表初始为 空
//      向链表头插入一个元素
//      删除第 k 个插入的数字后面的数字
//      在第 k 个插入的数字后面插入一个数字

#include <iostream>
using namespace std;

const int N = 1e5 + 10;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点 i 的 next 指针是多少
// idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;

void init() {
    head = -1, idx = 0;  // head 指向 -1， idx 指向 0 ，初始化一个空的链表
}

void addToHead(int x) {
    // 将值为 x 的节点插入到链表头
    e[idx] = x;
    ne[idx] = head; // idx 的下一个指针，更新为 头节点。
    head = idx++;   // 头节点等于 idx， idx 向后移动 
}

void add(int k, int x) {
    // 将 x 插入到下标是 k 的节点的后面
    e[idx] = x;
    ne[idx] = ne[k]; // idx 的下一个指针，更新为 k 的下一个 指针
    ne[k] = idx++;   // k 节点的下一个指针，指向 idx，idx 向后移动
}

void remove(int k) {
    // 删除下标为 k 的节点后面的一个节点
    ne[k] = ne[ne[k]]; // 直接将 k 节点的下一个指针，指向 下一个节点的下一个节点
}

int main() {
    init();

    int m = 0;
    cin >> m;
    while (m--) {
        char op;
        int k = 0, x = 0;
        cin >> op;
        if (op == 'H') {
            cin >> x;
            addToHead(x);
        } else if (op == 'D') {
            cin >> k;
            if (k == 0)
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

// https://www.acwing.com/activity/content/code/content/1451069/
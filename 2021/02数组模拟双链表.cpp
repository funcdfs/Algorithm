// 实现一个双链表初始为 空
// 相关操作为：
//      在最左侧插入一个数字
//      在最右侧插入一个数字
//      将第 k 个插入的数字删除
//      在第 k 个插入的数字的左侧插入一个数字
//      在第 k 个插入的数字的右侧插入一个数字


#include <iostream>
using namespace std;

const int N = 100010;

int e[N], l[N], r[N], idx;

void insert(int a, int x) { // 在 a 及节点后面插入一个节点
    e[idx] = x; 
    l[idx] = a, r[idx] = r[a];  // 新插入节点的左指针指向 a，新插入节点的右指针指向 a 的右指针 
    l[r[a]] = idx, r[a] = idx++; // 剩余两条边
}

void remove(int a) { // 删除节点 a
    l[r[a]] = l[a];  // a 的右侧节点的左侧指针，指向 a 的左侧指针
    r[l[a]] = r[a];  // a 的左侧节点的右侧指针，指向 a 的右侧指针
}

void init() {
    // 0 是左端点 1 是右端点
    l[0] = 0, r[0] = 1; // 0 节点的右侧指针指向 1
    l[1] = 0, r[1] = 0; // 1 节点的左侧指针指向 0
    idx = 2;   // 开头的两个节点当做是头节点和尾结点, 所以 idx 初始值为 2
}

int main() {
    int m = 0;
    cin >> m;

    init();

    while (m--) {
        string op;
        cin >> op;
        int k, x;

        if (op == "L") {
            cin >> x;
            insert(0, x); // 在最左侧插入一个元素
        } else if (op == "R") {
            cin >> x;
            insert(l[1], x); // 在最右侧插入一个元素
        } else if (op == "D") {
            cin >> k;
            remove(k + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            insert(l[k + 1], x);
        } else {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1461777/
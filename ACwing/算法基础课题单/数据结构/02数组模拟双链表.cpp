#include <iostream>
using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

// 在节点 a 的右边插入一个数x
void insert_Commented(int a, int x) {
    e[idx] = x;  // 节点的值导入
    l[idx] = a, r[idx] = r[a];
    // 新节点左边连接 a 。    
    // 新节点的右边连接 原本 a 的右边（先进行由节点本身开始从内向外的连接）
    l[r[a]] = idx, r[a] = idx++;
    // a 节点的右侧节点，的连接更新为 idx 。a 节点的右侧连接 idx 
    // idx 执行加一的操作
}

void insert(int a, int x) {
    e[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx++;
}

// 删除节点 a 
void remove(int a) {
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

int main() {
    cin >> m;

    // 0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;

    while (m--) {
        string op;
        cin >> op;
        int k, x;
        if (op == "L") {
            cin >> x;
            insert(0, x);
        } else if (op == "R") {
            cin >> x;
            insert(l[1], x);
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
    // 下标挺烦人的，理解算法的原理之后背会，遇到可以写出来就好！！
    return 0;
}
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int e[N], ne[N], head, idx;

void init() { head = -1, idx = 0; }

void addToHead(int x) { e[idx] = x, ne[idx] = head, head = idx++; }
void add(int k, int x) { e[idx] = x, ne[idx] = ne[k], ne[k] = idx++; }
void remove(int k) { ne[k] = ne[ne[k]]; }

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
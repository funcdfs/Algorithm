#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int h[N], e[N], ne[N], w[N], idx;
void add(int a, int b, int c) {
   e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int n, m;

int dijkstraHeap() {
   vector<int> dist(n + 1, 1e9);
   vector<bool> st(n + 1, false);
   dist[1] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> hp;
   hp.push({0, 1});
   while (hp.size()) {
      auto [d, id] = hp.top();
      hp.pop();
      if (st[id] == true) continue;
      st[id] = true;
      for (int i = h[id]; i != -1; i = ne[i]) {
         int j = e[i];
         if (dist[j] > d + w[i]) {
            dist[j] = d + w[i];
            hp.push({dist[j], j});
         }
      }
   }
   if (dist[n] == 1e9) return -1;
   return dist[n];
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   cin >> n >> m;

   memset(h, -1, sizeof h);
   for (int i = 0; i < m; i++) {
      int a = 0, b = 0, c = 0;
      cin >> a >> b >> c;
      add(a, b, c);
   }
   cout << dijkstraHeap() << '\n';

   return 0;
}
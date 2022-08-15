#include <cstring> 
#include <iostream>
#include <algorithm>
#include <queue> 

using namespace std; 

const int N = 100010; 

int n, m; 
int h[N], w[N], e[N], ne[N], idx; 
int dist[N]; 
bool st[N]; 

void add(int a, int b, int c) {
    e[idx] = b; 
    w[idx] = c; 
    ne[idx] = h[a]; 
    h[a] = idx++; 
}

int main() {
    
}
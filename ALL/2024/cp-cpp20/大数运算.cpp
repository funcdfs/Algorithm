#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    string a, b;
    cin >> a >> b;

    int na = 1, nb = 1;
    if (a[0] == '0') na = -1, a = a.substr(1);
    if (b[0] == '0') nb = -1, b = b.substr(1);

    vector<int> A, B;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for (int i = (int)b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }
    if (na * nb > 0) {
        
    }
    return 0;
}
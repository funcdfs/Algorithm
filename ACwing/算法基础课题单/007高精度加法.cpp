#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;
    if (A.size() < B.size()) 
        return add(B, A);

    int t = 0; // 用 t 表示三个数字的和
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size())  // i 没有超过 A 的范围， i 没有超过 B 的范围
            t += B[i];

        C.push_back(t % 10);
        t /= 10;
    }
    
    if (t) C.push_back(1);
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;

    auto C = add(A, B);

    for (int i = C.size(); i >= 0; i--) printf("%d", C[i]);
    return 0;
}
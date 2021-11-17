// 对于方程组的系数矩阵：

/* 初等行列变换*/
// 把某一行乘上一个非零的数字，
// 交换某两行数字
// 把某一行的若干倍加到另一行上去

// 把系数矩阵变成一个上三角形的形式
// a1x1 + ...      + amxn = b1
//     a2x2 + ... + a2nxn = b2
//                  xn = bn

// 1. 完美阶梯型 唯一解
// 2. 出现左边没有未知数，右边系数非零， 无解
// 3. 出现了很多 0 == 0 的方程， n 个未知数， n - 1 个方程， 说明有无穷多组解

// 枚举每一列 c
// 找到下面所有行中，当前这一列，绝对值最大的那一行
// 将这一行换到最上面
// 将这一行的第一个数字变为 1 （一行内的数字同时进行除法）
// 激动人心的操作：把这一列除了第一个数字全部消为 0
//              为其他行执行：加减若干倍第一行 （初等行列变换中的 3）
//              然后依次考虑下一行，第一项变 1，后面的变 0
// 现在的系数矩阵就是一个阶梯型（倒三角形）的矩阵

// 求解：
// 倒着消 即可求得，所有的值，然后把系数矩阵，变为 方程组的样式
// 就是我们最后要求的答案

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 110;
const double eps = 1e-6;

int n;
double a[N][N];

int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; c++) {
        int t = r;
        for (int i = r; i < n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c])) t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i < n + 1; i++) swap(a[t][i], a[r][i]);
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];

        for (int i = r + 1; i < n; i++)
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--) a[i][j] -= a[r][j] * a[i][c];

        r++;
    }

    if (r < n) {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps) return 2;
        return 1;
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++) a[i][n] -= a[j][n] * a[i][j];

    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++) cin >> a[i][j];

    int t = gauss();

    if (t == 0) {
        for (int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
    } else if (t == 1)
        puts("Infinite group solutions");
    else
        puts("No solution");

    return 0;
}
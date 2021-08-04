// https://vjudge.net/problem/UVA-725

/*2021-07-23-10-52*/
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, kase = 0;
    char buf[99];

    while (scanf("%d", &n) == 1 && n) {
        int cnt = 0;

        if (kase++) printf("\n");
        for (int fghij = 1234;; fghij++) {
            int abcde = fghij * n;
            sprintf(buf, "%05d%05d", abcde, fghij);
            // 将两个数字转换为题解格式的字符串
            if (strlen(buf) > 10) break;
            // 如果将数字转换为字符串
            // 转换之后的长度大于 10 的话，说明之后的必然大于十，没有继续for的意义了
            sort(buf, buf + 10);
            // 对字符串中的字符进行排序
            bool ok = true;
            for (int i = 0; i < 10; i++)
                if (buf[i] != '0' + i) ok = false;
            if (ok) {
                cnt++;
                printf("%05d / %05d = %d\n", abcde, fghij, n);
            }
        }
        if (!cnt) printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
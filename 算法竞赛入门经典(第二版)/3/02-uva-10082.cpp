#include <iostream>
using namespace std;
/*2021-05-25-21-19*/
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
// 从左面到右面，从上面到下面，对键盘进行打表
int main() {
    int i, c;
    while ((c = getchar()) != EOF) {
        for (i = 1; s[i] && s[i] != c; i++)
            ;  // 找错位之后的字符在常量表中的位置
        if (s[i])
            putchar(s[i - 1]);  // 如果找到，则输出它的前一个字符
        else
            putchar(c);
    }
    return 0;
}
//定义常量数组往往可以简化代码，无需计算大小
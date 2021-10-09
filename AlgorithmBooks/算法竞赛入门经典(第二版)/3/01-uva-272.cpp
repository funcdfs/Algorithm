#include <cstdio>
using namespace std;

int main() {
    int c, q = 1;
    //:::
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", (q ? "``" : "''"));
            q = !q;  //根据首位引号进行不同的输出，用三目运算符可以使程序简短并且语义明确
        } else {
            printf("%c", c);
        }
    }  //:::
    return 0;
}
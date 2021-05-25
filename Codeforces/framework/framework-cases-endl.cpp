#include <iostream>
#include <vector>
using namespace std;
int main() {
    size_t cases = 0;
    cin >> cases;
    size_t endlNumber = cases;

    for (size_t i = 0; i < cases; i++) {
        if (endlNumber > 1) {
            endlNumber -= 1;
            cout << endl;
        }
    }

    return 0;
}
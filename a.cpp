// erasing from list
#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> a;
    for (int i = 0; i < 5; i++) {
        a.push_back(i);
    }

    auto it1 = a.begin();
    auto it2 = a.rend();
    
    

    return 0;
}
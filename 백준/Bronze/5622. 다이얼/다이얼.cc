#include <iostream>
#include <string>
using namespace std;

int getNum(char c) {
    if (c <= 'C') return 2;
    if (c <= 'F') return 3;
    if (c <= 'I') return 4;
    if (c <= 'L') return 5;
    if (c <= 'O') return 6;
    if (c <= 'S') return 7;
    if (c <= 'V') return 8;
    return 9;
}

int main() {
    string word;
    cin >> word;
    
    int total = 0;
    for (char c : word) {
        total += getNum(c) + 1;
    }
    
    cout << total;
    return 0;
}
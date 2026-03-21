#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int na = stoi(a);
    int nb = stoi(b);
    
    cout << (na > nb ? na : nb);
    return 0;
}
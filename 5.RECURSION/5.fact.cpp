#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    if (n < 0) {
        cout << "Invalid input" << endl;
        return -1; 
    } 
    if (n == 0 || n == 1) {
        return 1; 
    return n * fact(n - 1); 
    }
}

int main() {
    int n;
    cin >> n;
    int f = fact(n);
    if (f != -1) {
        cout << f;
    }
    return 0;
}


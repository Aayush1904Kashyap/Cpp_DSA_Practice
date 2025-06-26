#include <bits/stdc++.h>
using namespace std;

class TwoStack {
    int* arr;
    int top1;
    int top2;
    int size;

public:
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        } 
    }

    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        } 
    }

    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1;
        }
    }

  
};

int main() {
    TwoStack ts(10);

    ts.push1(1);
    ts.push1(2);
    ts.push1(3);

    ts.push2(100);
    ts.push2(200);
    ts.push2(300);

    cout << "Popping from Stack1: ";
    cout << ts.pop1() << " "; // 3
    cout << ts.pop1() << " "; // 2
    cout << ts.pop1() << " "; // 1
    cout << ts.pop1() << endl; // -1

    cout << "Popping from Stack2: ";
    cout << ts.pop2() << " "; // 300
    cout << ts.pop2() << " "; // 200
    cout << ts.pop2() << " "; // 100
    cout << ts.pop2() << endl; // -1

    return 0;
}

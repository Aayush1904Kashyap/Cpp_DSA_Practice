#include<bits/stdc++.h>
using namespace std;

int main() {

   int N=13;
    int i=2;
    if((N&(1<<i))!=0){
        cout<<"set";
    }else{
        cout<<"unset";
    }
}

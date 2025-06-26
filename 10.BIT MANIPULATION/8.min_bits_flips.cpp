#include<bits/stdc++.h>
using namespace std;

int main() {

   int N=8;
   int G=7;
   int ans=N^G;
   int cnt=0;
   for(int i=0;i<31;i++){
      if(ans&(1<<i)){
         cnt++;
      }
   }
   cout<<cnt;
}

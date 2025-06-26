#include<bits/stdc++.h>
using namespace std;
void print1(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<"X ";
        }
        cout<<"\n";
    }
}
void print2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"X ";
        }
        cout<<"\n";
    }
}
void print3(int n){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<"\n";
    }
}
void print4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
        }
        cout<<"\n";
    }
}
void print5(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"X ";
        }
        cout<<"\n";
    }
}
void print6(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<"\n";
    }
}
void print7(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=(2*i-1);j++){
            cout<<"X ";
        }
        cout<<"\n";
    }

}
void print8(int n){
    for(int i=n;i>=1;i--){
        for(int j=0;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=(2*i-1);j++){
            cout<<"X ";
        }
        cout<<"\n";
    }
    
}
void print9(int n){
     for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=(2*i-1);j++){
            cout<<"X ";
        }
        cout<<"\n";
    }
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=(2*i-1);j++){
            cout<<"X ";
        }
        cout<<"\n";
    }
    
}
void print10(int n){
  for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"X ";
        }
        cout<<"\n";
    }
     for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"X ";
        }
        cout<<"\n";
    }
    
}
void print11(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j%2==0){
                cout<<"1 ";
            }else{
               cout<<"0 "; 
            }
        }
        cout<<"\n";
    }
}
void print12(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j<<" ";
        }
        for(int j=1; j<=2*(n-i); j++){
            cout << "  ";
        }
        for(int j=i; j>=1; j--){
            cout << j<<" ";
        }
        cout << "\n";
    }
}
void print13(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}
void print14(int n){
    
    for(int i=1;i<=n;i++){
        int ch=65;
        for(int j=1;j<=i;j++){
            cout<<char(ch)<<" ";
            ch++;
        }
        cout<<endl;
    }
}
void print15(int n){
    
    for(int i=n;i>=1;i--){
        int ch=65;
        for(int j=1;j<=i;j++){
            cout<<char(ch)<<" ";
            ch++;
        }
        cout<<endl;
    }
}
void print16(int n){
    int ch=65;
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=i;j++){
            
            cout<<char(ch)<<" ";
           
        }
         ch++;
        cout<<endl;
    }
}
void print17(int n){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i-1;j++){
            cout<<" ";
        }
        char ch='A';
        int breakpoint=(2*i+1)/2;
        for(int j=0;j<2*i+1;j++){
            cout<<ch;
            if(j<breakpoint){
                ch++;
            }else{
                ch--;
            }

        }

        for(int j=0;j<=n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void print18(int n) {
    for (int i = 1; i <= n; i++) {
        for (char ch = 'A' + n - i; ch <= 'A' + n - 1; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void print19(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"x ";
        }
        for(int j=1; j<=2*(n-i); j++){
            cout << "  ";
        }
        for(int j=i; j>=1; j--){
            cout <<"X ";
        }
        cout << "\n";
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"x ";
        }
        for(int j=1; j<=2*(n-i); j++){
            cout << "  ";
        }
        for(int j=i; j>=1; j--){
            cout <<"X ";
        }
        cout << "\n";
    }
}
void print20(int n){
       for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"x ";
        }
        for(int j=1; j<=2*(n-i); j++){
            cout << "  ";
        }
        for(int j=i; j>=1; j--){
            cout <<"X ";
        }
        cout << "\n";
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"x ";
        }
        for(int j=1; j<=2*(n-i); j++){
            cout << "  ";
        }
        for(int j=i; j>=1; j--){
            cout <<"X ";
        }
        cout << "\n";
    }

}
void print21(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1||i==n||j==1||j==n){
                cout<<"X ";
            }else{
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
}
void print22(int n){
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int top = i;
            int left = j;
            int right = 2 * n - 1 - j - 1;
            int down =2 * n - 1 - i - 1;
            cout << (n - min(min(top, down), min(left, right))) << " ";
        }
        cout << "\n";
    }
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        print22(n);
        cout<<endl;
    }
    return 0;
}
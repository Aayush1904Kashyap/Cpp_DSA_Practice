/*ALGORITHM
push the maximum to the last by adjacent swapping
Initial array: [13, 46, 24, 52, 20, 9]
First Pass:
2. Swap 46 and 24: [13, 24, 46, 52, 20, 9]
3. Swap 52 and 20: [13, 24, 46, 20, 52, 9]
4. Swap 52 and 9: [13, 24, 46, 20, 9, 52]

Second Pass:
5. Swap 46 and 20: [13, 24, 20, 46, 9, 52]
6. Swap 46 and 9: [13, 24, 20, 9, 46, 52]

Third Pass:
7. Swap 24 and 20: [13, 20, 24, 9, 46, 52]
8. Swap 24 and 9: [13, 20, 9, 24, 46, 52]

Fourth Pass:
9. Swap 20 and 9: [13, 9, 20, 24, 46, 52]

Fifth Pass:
10. Swap 13 and 9: [9, 13, 20, 24, 46, 52]

Final sorted array: [9, 13, 20, 24, 46, 52]

*/

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n){    
    for(int i=n-1;i>=0;i--){
        int didSwap=0;
        for(int j=0;j<=i-1;j++){
           if(arr[j]>arr[j+1]){
            int temp = arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            didSwap=1;
           }     
        }
        if(didSwap==0){
            break;
         }
    }
}

int main(){
     int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    bubble_sort(arr,n);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

//TC----> O(n^2)--->worst case/average also
//        O(n)----->best case
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr) {
	int n=arr.size();
    int cnt1=0;
    int cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i]!=el2){
            cnt1=1;
            el1=arr[i];
        }else if(cnt2==0 && arr[i]!=el1){
            cnt2=1;
            el2=arr[i];
        }else if(el1==arr[i]){
            cnt1++;
        }else if(el2==arr[i]){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1=0;cnt2=0;
    for(int i=0;i<n;i++)
    {
         if(arr[i]==el1)cnt1++;
         if(arr[i]==el2)cnt2++;
    }
    int mini=(int)(n/3)+1;
    if(cnt1>=mini)ls.push_back(el1);
    if(cnt2>=mini)ls.push_back(el2);

    sort(ls.begin(),ls.end());
    return ls;
}

int main() {
     int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = majorityElement(arr);

    if (!result.empty()) {
        cout << "ELEMENTS HAVING MAJORITY ARE: ";
        for (int el : result) {
            cout << el << " ";
        }
        cout << endl;
    } else {
        cout << "NO MAJOR ELEMENTS" << endl;
    }

    return 0;
}

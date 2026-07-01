#include <bits/stdc++.h>
using namespace std;
long long canEatAll(vector<int>& piles, int speed) {
    long long total = 0;
    int n = piles.size();

    for (int i = 0; i < n; i++) {
        total += ceil((double)piles[i] / (double)speed);
    }

    return total;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low=1;
    int high=*max_element(piles.begin(),piles.end());
    int ans=high;
    while(low<=high){
        int mid=low+(high-low)/2;
        long long totalhrs=canEatAll(piles,mid);
        if(totalhrs<=h){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int h;
    cin >> h;

    int result = minEatingSpeed(piles, h);
    cout << result << endl;

    return 0;
}
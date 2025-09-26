#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n, k ;
    cin >> n >> k ;
    vector<int> arr(n) ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    long long sum = 0;
    int l = 0;
    int min_l = INT_MAX;
    
    for (int r = 0; r < n; r++) {
        sum += arr[r];
        while (sum >= k) {
            min_l = min(min_l, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }
    cout << min_l << endl ;
    return 0;
}

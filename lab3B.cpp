#include <bits/stdc++.h>
using namespace std;

bool can_div(const vector<int>& a, int k, long long maxSum){
    int blocks = 1 ;
    long long cur = 0 ;
    for(int i = 0 ; i< a.size(); i++){
        if(a[i]> maxSum){
            return false;
        }
        if(cur+a[i]>maxSum){
            blocks++ ;
            cur = a[i] ;
        }
        else{
            cur += a[i];
        }
    }
    return blocks <= k ;
}
int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> arr(n) ;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i] ;   
    }
    long long l = *max_element(arr.begin(), arr.end());
    long long r = accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = r ;
    while(l<=r){
        long long mid = l+(r-l)/2 ;
        if(can_div(arr, k, mid)){
            ans = mid ;
            r = mid -1 ;
        }
        else{
            l = mid+1 ;
        }
    }
cout << ans << endl ;
return 0;
}
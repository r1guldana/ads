#include <bits/stdc++.h>
using namespace std ;
int main(){
    long long  n , f ;
    cin >> n >> f ;

    vector<long long>children(n);
    for (int i = 0; i < n; i++)
    {
        cin >> children[i];
    }
    long long l = 1;
    long long r = 0 ;
    
    for (int i = 0; i < n; i++) {
    if (children[i] > r) {
        r = children[i];
    }
}
    long long ans = r ;
while(l<=r){
    long long mid = l+(r-l)/2 ; 
    long long flights = 0;
    for(int i = 0 ; i<n; i++){
        flights +=  (children[i]+mid-1)/mid ;
    }
    if(flights<= f){
        ans = mid;
        r = mid - 1;
    }
    else{
        l = mid+1;
    }
}
cout << ans << endl ;
   return 0; 
}

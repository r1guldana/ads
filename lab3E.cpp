#include <bits/stdc++.h>
using namespace std ;
int main(){
    int n, k ;
    cin >> n >> k ;
    vector<pair<int, int> > pastures(n); //x2 y2
    for(int i = 0 ; i < n ; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        pastures[i] = make_pair(x2, y2);

    }
    int l = 0;
    int r = 1000000000 ;
    int ans = -1 ;
    while(l<=r){
        int mid = (l+r)/2 ;
        int count = 0 ;
        for (int i = 0; i < n; i++) {
            int x = pastures[i].first;
            int y = pastures[i].second;
            if(x<= mid && y<=mid){
                count++ ;
            }
        }
            if(count>=k){
                ans = mid;
            r = mid - 1;
            }
            else{
                l = mid+1 ;
            }

    }
    cout << ans << endl ;
    return 0;
}
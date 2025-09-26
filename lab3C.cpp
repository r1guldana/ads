#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n, q ;
    cin >> n >> q ;
    vector<long long> lines(n) ;
    for(int i = 0 ; i < n ; i++){
        
        cin >> lines[i] ;
        
    }
    
   while (q--)
        {
            long long count = 0;
            int l1, r1, l2, r2;
            cin >>l1>> r1>> l2>> r2;
        
    for(int i = 0 ; i<n ; i++){
        
        if((l1<=lines[i] && lines[i]<= r1) || (l2<= lines[i] && lines[i]<= r2 )){
            count ++ ;
        }
    }
    cout<< count << endl;
}
return 0;
}
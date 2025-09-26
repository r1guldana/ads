#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n, m ;
    cin >> n >> m ;
    vector<int> lines(n) ;
    for(int i = 0 ; i < n ; i++){
        
        cin >> lines[i] ;
        
    }
    
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + lines[i-1];
    }

    for (int i = 0; i < m; i++) {
        int error_line;
        cin >> error_line;

        int l, r;
        l = 1;
        r = n;
        int block_num = 1;

        while (l<=r)
        {
            int mid =  l+(r-l)/2;
            if(error_line<=prefix[mid]){
                block_num = mid ;
                r = mid-1 ;
            }
            else{
                l = mid+1;
            }
        }
        cout << block_num << endl;
        
} return 0;
}
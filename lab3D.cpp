#include <bits/stdc++.h>
using namespace std ;
int count_f(const vector<int>& a, int l, int r){
  
    return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);


}
int main(){
    int n, q ;
    cin >> n >> q ;
    vector<int> lines(n) ;
    for(int i = 0 ; i < n ; i++){
        cin >> lines[i] ;
    }
    sort(lines.begin(), lines.end());
    
   while (q--)
        {
            long long count = 0;
            int l1, r1, l2, r2;
            cin >>l1>> r1>> l2>> r2;
        int c1 = count_f(lines , l1, r1) ;
        int c2 = count_f(lines , l2, r2) ;
            int overlap = 0;
            if (max(l1, l2) <= min(r1, r2)) {
    overlap = count_f(lines, max(l1, l2), min(r1, r2));
}
cout << c1+c2-overlap << endl;
}
return 0;
}
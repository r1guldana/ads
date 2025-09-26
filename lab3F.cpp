#include <bits/stdc++.h>
using namespace std ;
pair<int, int> rounds(const vector<int>& a, int m){
    int count = 0;
    int sum = 0 ;
    for(int i = 0 ; i<a.size(); i++){
        if(m>= a[i]){
            count++;
            sum += a[i];
        }
    }
    return make_pair(count, sum);
}

int main(){
    int n ;
    cin >> n  ;
    vector <int>  powers(n); //x2 y2
    for(int i = 0 ; i < n ; i++){
        cin >> powers[i] ;
    }

    int p ;
    cin >> p;
    vector<pair<int, int> > competitions(p) ;
    for(int i = 0 ; i<p; i++){
        int m;
        cin >> m ;
        competitions[i] = rounds(powers, m);
    }
    for (int i = 0; i < p; i++) {
    cout << competitions[i].first << " " << competitions[i].second << endl;
}
   

    return 0;
}
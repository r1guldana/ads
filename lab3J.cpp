#include <bits/stdc++.h>
using namespace std ;

int main(){
    int N, H ;
    cin >> N >> H ;
    vector<long long> bags ;
    for(int i = 0 ; i<N ; i++){
        int j ;
        cin >> j ;
        bags.push_back(j);
    }
    long long l = 1 ;
    long long r = 0; 
    for (int i = 0; i < N; i++) {
    if (bags[i] > r) {
        r = bags[i];
    }
}
    while(l<r){
        long long K = l+(r-l)/2 ; // == (l+r)/2 ;
        long long hour = 0;

        for (int i = 0; i < N; i++)
        {
            hour = hour + (bags[i]+K-1)/K;
        }
        if(hour <= H){
            r = K ;
        }
        else{
            l = K + 1 ;
        }
        


    

}
cout << l << endl;
    
    return 0;
}
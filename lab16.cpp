#include <bits/stdc++.h>
using namespace std;
int main(){
    vector <long long> prime ;
    for(int i = 2 ; i <= 100000 ; i++){
        bool is_prime = true;

        for(int j = 2 ; j*j <= i ; j++){ // i > j**0.5
            if(i % j == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            prime.push_back(i);
        }
    }
    int n;
    cin >> n;
    cout << prime[n-1] << endl;
    return 0;
}
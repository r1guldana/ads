#include   <iostream>
#include <vector>
using namespace std;
int Binarysearch(const vector<int>& arr, int n){
    int l = 0; 
    int r = arr.size()-1 ;
    while(l<=r){
        int mid = l+(r-l)/2 ;
        if(arr[mid]==n){
            return mid ;
        }
        else if(arr[mid]<n){
            l = mid +1 ;
        }
        else{
            r = mid -1 ;
        }
}
return -1;
}
int main(){
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i] ;   
    }
    int num ;
    cin >> num ;
    cout << Binarysearch(arr, num) << endl ;
 return 0;
}
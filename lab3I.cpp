#include <iostream>
#include <vector>
using namespace std;

int binary_search_exact(vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;  
        if (a[mid] == x) return true;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return false ; 
}

int main() {
     int n ;
     cin >> n ;
    vector<int> arr ;
   for(int i = 0 ; i<n; i++){
    int a ;
    cin >> a ;
    arr.push_back(a);
   }

   int x ;
   cin >> x ;
   if(binary_search_exact(arr, x)){
    cout<< "Yes" ;
   }
   else{
    cout << "No" ;
   }
return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int a[1000] ;
void quick_sort(int l, int r){
    int i = l ;   // [l ... j][mid][i ... r] 
    int j = r ;
    int p = a [(l+r)/2] ;   //middle element of the a 
    while(i<j){
        while(a[i]< p) i++ ;
        while(a[j]> p) j-- ;
         if(i<=j){
            swap(a[i], a[j]);
            i++ ;
            j-- ;
         }
    }
    if(l<j)quick_sort(l, j);
    if(i<r)quick_sort(i, r);
    
} 
int main(){
    int n ;
    cin >> n ;

    for (int i = 0 ; i < n ; i++){
        cin >> a[i] ;
        
    }
    quick_sort(0, n-1) ;

    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " " ;
    }
    return 0 ;
}
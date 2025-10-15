#include <iostream>

using namespace std;
int a[1000];

void merge(int l, int m, int r) {
    int i = l;
    int j = r ;
    int k = l;
    int n1 = m-l+1 ;
    int n2 = r-(m+1)+1 ;
    int uk1 =0;
    int uk2 =0;
    while(uk1)

}

void mergesort(int l, int r) {
    int mid = (l+r)/2 ;
    mergesort(l, mid);
    mergesort(mid + 1, r);

    
}

int main() {
    int n ;
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i] ;   
    }
    mergesort(0, n - 1);
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " " ;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a[1000] ;

void merge(char l, int m, char r) {
    int ll = 0 ;
    int rr = m ;;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = a[m + 1 + i];
    }

    int uk1 = 0;
    int uk2 = 0;
    int k = l;
    while (uk1 < n1 && uk2 < n2) {
        if (L[uk1] <= R[uk2]) {
            a[k] = L[uk1];
            uk1++;
        } else {
            a[k] = R[uk2];
            uk2++;
        }
        k++;
    }

    while (uk1 < n1) {
        a[k] = L[uk1];
        uk1++; k++;
    }
    while (uk2 < n2) {
        a[k] = L[uk2];
        uk2++; k++;
    }

}

void mergesort(char l, char r) {
    if (l < r ) {
        int m = ( + ) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, m, r);
    }
}
 
int main(){
    string n ;
    cin >> n ;
}
#include <bits/stdc++.h>
using namespace std ;

int binarySearch(const vector<int>& row, int trgt, bool incr) {
    int l = 0, r = row.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (row[mid] == trgt) return mid;
        if (incr) {
            if (row[mid] < trgt) l = mid + 1;
            else r = mid - 1;
        } 
        else {
            if (row[mid] > trgt) l = mid + 1;
            else r = mid - 1;
        }
    }
    return -1;
}

int main(){ 
    int t ;
    int n, m ;
    cin >> t ;
    
    vector<int> arr(t) ;
    for(int i = 0 ; i < t ; i++){
        cin >> arr[i] ;   
    }
    cin >> n >> m ;
    vector<vector<int> > snake(n, vector<int>(m)  );
    for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        cin >> snake[i][j];
    }

}
for (int val= 0 ; val<t ; val++) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        int j = binarySearch(snake[i], arr[val], i % 2 == 1); // true если строка возрастающая
        if (j != -1) {
            cout << i << " " << j << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "-1" << endl;
}
  
 return 0;
}
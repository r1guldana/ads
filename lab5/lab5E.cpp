#include <iostream>
#include <vector>
#include <string>
using namespace std ;

class MinHeap {
    public:
    vector<int> a;
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    int getMin() {
        return a[0];
    }
    int size(){
        return a.size() ;
    }
    
    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;

        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;

        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);

        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int root_value = getMin();

        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);

        return root_value;
    }
};
int main(){
    int q;
    long long k ;
    cin >> q >> k ;
    MinHeap* heap = new MinHeap() ;
    long long sum = 0;
    for(int i = 0 ; i < q; i++){
        string query ;
        cin >> query ;
        if(query == "insert"){
            int x ;
            cin >> x ;
            if(heap->size()<k){
            heap->insert(x);
            sum+=x ;
            }
            else if(x>heap->getMin()){
                sum -= heap->getMin() ;
                heap->extractMin();
                heap->insert(x);
                sum += x ;
            }
        }
        else if(query == "print"){
            cout << sum << endl ;
        }

    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

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

     int size() { 
        return a.size(); 
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
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < a.size() && a[l] < a[smallest])
            smallest = l;
        if (r < a.size() && a[r] < a[smallest])
            smallest = r;

        if (smallest != i) {
            swap(a[i], a[smallest]);
            heapify(smallest);
        }
    }
    int extractMin() {
        if(a.empty()) {
            return 0 ;
        }

        int root_value = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    MinHeap *heap = new MinHeap();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap->insert(x);
    }
    int operations = 0 ;

    while(heap->getMin() < m && heap->size()>=2){
        
        int d_first = heap->extractMin();
        int d_second = heap->extractMin();
        int d_new = d_first  + 2 * d_second ;
        heap->insert(d_new);
        operations++ ;  
    }
    if(heap -> getMin() < m ){
            cout << -1 << endl ;
            return 0 ;
        }
    else{
        cout << operations << endl;
        }
        return 0;
}
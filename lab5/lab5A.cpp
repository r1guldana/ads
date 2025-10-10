#include <iostream>

#include <vector>
#include <algorithm>

using namespace std ;

class minHeap{
    vector<long long> a ;
public:
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1; }
    int right(int i ){ return 2*i+2 ; }
     long long getMin() {
        if(a.empty())return -1;
        return a[0];
    }
    int size() {  
        return a.size();
    }

    void insert(long long k) {
        a.push_back(k);
        int ind = a.size() - 1;
        while (ind > 0 && a[ind] < a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        int sm = i ;
        int l= left(i);
        int r = right(i);
       
        if (l < a.size() && a[l] < a[sm]) sm = l;
        if (r < a.size() && a[r] < a[sm]) sm = r;
            

        if (sm != i) {
            swap(a[i], a[sm]);
            heapify(sm);
        }
    }

    long long extractMin() {
        if(a.empty())return -1;
        long long root_value = a[0];
        a[0] = a.back();
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }
};

int main() {
    int n;
    cin >> n;
    minHeap *heap = new minHeap();
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        heap->insert(x);
    }
    long long totalCost = 0;

    while (heap->size()> 1) {
        long long firstMin = heap->extractMin();
        long long secondMin = heap->extractMin();
        long long cost = firstMin + secondMin;
        totalCost += cost;
        heap->insert(cost);
        
    }
    cout << totalCost << endl;
    delete heap;
    return 0;
}

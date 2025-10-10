#include <iostream>
#include <vector>

using namespace std;

class MAXHeap {
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

    int getMax() {
        return a[0];
    }
     bool empty() {
        return a.empty();
    }

    void insert(int k) {
        a.push_back(k);
        int ind =(int) a.size() - 1;

        while (ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
     int n = (int)a.size();
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(largest);
    }
    }

    int extractMax() {
        
        int root_value = a[0];
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
    MAXHeap *heap = new MAXHeap();

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap->insert(x);
    }
   while(heap->a.size() > 1) {
        int x = heap->extractMax();
        int y = heap->extractMax();
        if(x != y) heap->insert(x-y);
     
    }
    if(heap->empty()) cout << 0;
    else cout << heap->getMax();
    return 0;
}
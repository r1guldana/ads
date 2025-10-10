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

    int getMax() {
        return a[0];
    }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size() - 1;
        while (ind > 0 && a[ind] > a[parent(ind)]) {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }
    void heapify(int i) {
        if (left(i) < a.size() - 1)
            return;
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)])
            j = right(i);
        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    int extractMax() {
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root_value;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    MinHeap *heap = new MinHeap();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap->insert(x);
    }
    long long sum = 0;
    for (int i = 0; i < k; i++){
        int price = heap->extractMax();
        sum += price;
        if(price>1){
            heap->insert(price-1);
        }
    }
    cout << sum << " ";
    return 0;
}
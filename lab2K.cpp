#include <iostream>
#include <string>

using namespace std;

struct CharCounter {
    char chars[26];  
    int counts[26];
    int size;
    
    CharCounter() {
        size = 0;
        for (int i = 0; i < 26; i++) {
            chars[i] = '\0';
            counts[i] = 0;
        }
    }
    
    void add(char c) {
        for (int i = 0; i < size; i++) {
            if (chars[i] == c) {
                counts[i]++;
                return;
            }
        }
        chars[size] = c;
        counts[size] = 1;
        size++;
    }
    
    int getCount(char c) {
        for (int i = 0; i < size; i++) {
            if (chars[i] == c) {
                return counts[i];
            }
        }
        return 0;
    }
    
    void clear() {
        size = 0;
        for (int i = 0; i < 26; i++) {
            chars[i] = '\0';
            counts[i] = 0;
        }
    }
};

class Node {
public:
    char data;
    Node* next;
    Node(char c) {
        this->data = c;
        this->next = NULL;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;
    CharCounter counter;

    Queue() {
        head = tail = NULL;
    }

    void push(char c) {
        Node* newNode = new Node(c);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        counter.add(c);
    }

    void pop() {
        if (head == NULL) return;
        
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    }

    char front() {
        if (head == NULL) return '\0';
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }

    char findFirstUnique() {
        Node* current = head;
        while (current != NULL) {
            if (counter.getCount(current->data) == 1) {
                return current->data;
            }
            current = current->next;
        }
        return '-';
    }

    void solve() {
        int n;
        cin >> n;
        while (!empty()) {
            pop();
        }
        counter.clear();
        
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            push(c);
            
            char result = findFirstUnique();
            if (result == '-') {
                cout << "-1";
            } else {
                cout << result;
            }
            
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    int T;
    cin >> T;
    
    Queue q;
    for (int t = 0; t < T; t++) {
        q.solve();
    }
    
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string book_name;
    Node* prev;
    Node* next;
    Node(string name) : book_name(name), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(NULL), tail(NULL), size(0) {}

    void add_front(string book_name) {
        Node* new_node = new Node(book_name);
        if (head == NULL) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
        cout << "ok" << endl;
    }

    void add_back(string book_name) {
        Node* new_node = new Node(book_name);
        if (tail == NULL) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
        cout << "ok" << endl;
    }

    void erase_front() {
        if (head == NULL) {
            cout << "error" << endl;
            return;
        }
        
        string erased_book = head->book_name;
        Node* temp = head;
        
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        
        delete temp;
        size--;
        cout << erased_book << endl;
    }

    void erase_back() {
        if (tail == NULL) {
            cout << "error" << endl;
            return;
        }
        
        string erased_book = tail->book_name;
        Node* temp = tail;
        
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        
        delete temp;
        size--;
        cout << erased_book << endl;
    }

    void front() {
        if (head == NULL) {
            cout << "error" << endl;
        } else {
            cout << head->book_name << endl;
        }
    }

    void back() {
        if (tail == NULL) {
            cout << "error" << endl;
        } else {
            cout << tail->book_name << endl;
        }
    }

    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        size = 0;
        cout << "ok" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    string command;

    while (true) {
        cin >> command;

        if (command == "add_front") {
            string book_name;
            cin >> book_name;
            list.add_front(book_name);
        }
        else if (command == "add_back") {
            string book_name;
            cin >> book_name;
            list.add_back(book_name);
        }
        else if (command == "erase_front") {
            list.erase_front();
        }
        else if (command == "erase_back") {
            list.erase_back();
        }
        else if (command == "front") {
            list.front();
        }
        else if (command == "back") {
            list.back();
        }
        else if (command == "clear") {
            list.clear();
        }
        else if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }

    return 0;
}
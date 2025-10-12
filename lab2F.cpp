#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class insert {
public:
        Node* insert_data(Node* head, Node*tail,  int data, int pos , int size) {
        Node* new_node = new Node(data);
        if (pos == 0) {
            new_node->next = head;
            head = new_node;
            return head;
        }
        else if(pos == size){
            tail ->next = new_node;
            tail = new_node;
            return head;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            new_node->next = temp->next;
            temp->next = new_node;
        }
        return head;
    }
};
int main() {
    int n;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    int data, position;
    cin >> data >> position;
    insert ins;
    head = ins.insert_data(head, tail , data, position, n);   
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}

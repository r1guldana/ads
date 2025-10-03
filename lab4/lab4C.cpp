#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST{
    
    public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data <= node->data) 
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);

            return node;
    }
      Node *search(Node *node, int data) {
        if (node == NULL || node->data == data)
            return node;
        
        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

      void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    
    
    
};

int main() {
    BST *gifts = new BST();
    int n;
    cin >> n ;


    for(int i = 0 ; i<n;i++){
        int j;
        cin >> j;
         gifts->root = gifts->insert(gifts->root, j);
    }
    int k;
    cin >> k;
    Node* subroot = gifts->search(gifts->root, k);
    gifts-> preorder(subroot);
    return 0;
}
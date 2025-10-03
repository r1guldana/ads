#include <iostream>
#include <algorithm>
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

class BST {
public:
    Node* root;
    int max_dis ;
    
    BST() {
        root = NULL;
       max_dis = 0;
    }
    
    Node* insert(Node* node, int data) {
        if(node == NULL) {
            return new Node(data);
        }
        if(data < node->data) {
            node->left = insert(node->left, data);
        }
        else if(data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;      
    }
 int diameter(Node* node) {
        if(node == NULL) return 0;
        
        int l_height = diameter(node->left);
        int r_height = diameter(node->right);
        int dis = l_height + r_height;
        
        max_dis = max(max_dis, dis);
        return 1 + max(l_height, r_height);
    }
    
    int getDiameter() {
        max_dis = 0;
        diameter(root);
        return max_dis+1;
    }
};

int main() {
    int N;
    cin >> N;
    BST bst;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        bst.root = bst.insert(bst.root, val);
    }

    cout << bst.getDiameter() << endl;
    return 0;
}
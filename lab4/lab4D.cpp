#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> sum(Node* node) {
        vector <int> sums ;
         if (node == NULL) return sums;

          queue<Node*> q;
           q.push(node);
           while (!q.empty()) {
        int Size_lvl= q.size();
        int sum = 0;

        for(int i = 0; i<Size_lvl; i++){
            Node*cur = q.front() ;
            q.pop();
            sum += cur->data;

             if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        sums.push_back(sum);
}
        return sums;
}
};

int main() {
    BST *bst = new BST();
    int N, M ;
    cin >> N ;
    for(int i = 0 ; i<N;i++){
        int j;
        cin >> j;
         bst->root = bst->insert(bst->root, j);
    }

     vector<int> sums_lvl = bst->sum(bst ->root);
     cout<< sums_lvl.size() << endl ;
     for(int i = 0 ; i<sums_lvl.size(); i++){
        cout << sums_lvl[i] << ' ';
     }

   
 
    return 0;
}
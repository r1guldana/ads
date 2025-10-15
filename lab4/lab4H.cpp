#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    void inOrder(Node *node)
    {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void transform(Node *node, int &sum)
    {
        if (node == NULL)
            return;
        transform(node->right, sum);
        sum += node->data;
        node->data = sum;
        transform(node->left, sum);
    }
    void reverseInOrder(Node *node)
    {
        if (node == NULL)
            return;
        reverseInOrder(node->right);
        cout << node->data << " ";
        reverseInOrder(node->left);
    }
};

int main()
{
    int n;
    cin >> n;
    BST bst;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        bst.root = bst.insert(bst.root, val);
    }
    int sum = 0;
    bst.transform(bst.root, sum);

    bst.reverseInOrder(bst.root);
}
#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node *root, int x)
{
    if (!root)
        return new Node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
bool check(Node *node, int depth, int &leafDepth)
{
    if (!node)
        return true;
    if (!node->left && !node->right)
    {
        if (leafDepth == -1)
            leafDepth = depth;
        return leafDepth == depth;
    }
    if (!node->left || !node->right)
        return false;
    return check(node->left, depth + 1, leafDepth) &&
           check(node->right, depth + 1, leafDepth);
}

void perfect(const vector<int> &sorted, vector<int> &res, int l, int r)
{
    if (l > r)
        return;

    int mid = l + (r - l) / 2;
    res.push_back(sorted[mid]);
    perfect(sorted, res, l, mid - 1);
    perfect(sorted, res, mid + 1, r);
    // return root ;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int size = (1 << n) - 1;

    for (int i = 0; i < size; i++)
    {
        int j;
        cin >> j;
        arr.push_back(j);
    }
    Node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = insert(root, arr[i]);
    }
    int leafDepth = -1;
    bool ok = check(root, 1, leafDepth);

    if (ok && leafDepth == n)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        vector<int> res;
        perfect(sorted, res, 0, size - 1);
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

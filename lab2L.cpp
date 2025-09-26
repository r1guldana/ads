# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {
	if (head == NULL) return 0;

    long long max_ending = head->val;
    long long max_so_far = head->val;
    Node* cur = head->next;

    while (cur != NULL) {
        long long x = cur->val;
        max_ending = max(x, max_ending + x);
        max_so_far = max(max_so_far, max_ending);
        cur = cur->next;
    }

    return (int)max_so_far;
	
}

int main() {
  int n;
  cin >> n;

  Node*head;
  Node*tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << endl;
  return 0;
}

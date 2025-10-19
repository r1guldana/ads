#include <bits/stdc++.h>
using namespace std;
void quick_sort(vector<char> &a, int l, int r)
{
    char mid = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (a[i] < mid)
        {
            i++;
        }
        while (a[j] > mid)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        if (i < r)
        {
            quick_sort(a, i, r);
        }
        if (j > l)
        {
            quick_sort(a, l, j);
        }
    }
}
int main()
{
    string s;
    cin >> s;
    vector<char> letters(s.begin(), s.end());
    quick_sort(letters, 0, letters.size() - 1);

    for (int i = 0; i < letters.size(); i++)
    {
        cout << letters[i];
    }
    return 0;
}
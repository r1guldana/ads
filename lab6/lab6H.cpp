#include <iostream>
#include <vector>
#include <string>
using namespace std;
void quick_sort(vector<char> &a, int l, int r)
{
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (i < r)
        {
            i++;
        }
        while (l < j)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        if (l < j)
        {
            quick_sort(a, l, j);
        }
        if (i < r)
        {
            quick_sort(a, i, r);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<char> letters(n);
    for (int i = 0; i < n; i++)
    {
        cin >> letters[i];
    }
    char a;
    cin >> a;
    quick_sort(letters, 0, n - 1);
    char balanced = letters[0];

    for (int i = 0; i < n; i++)
    {
        if (letters[i] > a)
        {
            balanced = letters[i];
            break;
        }
    }
    cout << balanced<< endl;

    return 0;
}
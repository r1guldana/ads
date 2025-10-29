#include <bits/stdc++.h>
using namespace std;
bool comp(string L, string R){
    if(L.size() != R.size()){
        return L.size() < R.size();
    }
    else{L.size() > R.size();}
}
void merge(vector<string> &arr, long long left, long long mid, long long right)
{
    long long n1 = mid - left + 1;
    long long n2 = right - mid;
    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    long long i = 0;
    long long j = 0;
    long long k = left;
    while (i < n1 && j < n2)
    {
        if (comp(L[i], R[j]))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<string> &arr, long long left, long long right)
{
    if (left < right){
    long long mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    }
}
void printArray(vector<string> &arr)
{
    for (long long num = 0; num < arr.size(); num++)
        cout << arr[num] << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    cin.ignore();
    for (long long i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        vector<string> arr;
        string word = "";
        for (long long j = 0; j < s.size(); j++)
        {
            if (s[j] == ' ')
            {
                arr.push_back(word);
                word = "";
            }
            else
            {
                word += s[j];
            }
        }
        if (!word.empty())
        {
            arr.push_back(word);
        }
        mergeSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }
    return 0;
}
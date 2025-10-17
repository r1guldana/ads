#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<char> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // left subarray size
    int n2 = right - mid;    // right subarray

    vector<char> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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
void mergeSort(vector<char> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void PrintArr(vector<char> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
}
bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
    int n;
    cin >> n;
    string alphabet;
    cin >> alphabet;
    vector<char> vowel;
    vector<char> consonants;
    vector<char> alph;

    for (int i = 0; i < n; i++)
    {
        if (isVowel(alphabet[i]))
        {
            vowel.push_back(alphabet[i]);
        }
        else
        {
            consonants.push_back(alphabet[i]);
        }
    }
    mergeSort(vowel, 0, vowel.size() - 1);
    mergeSort(consonants, 0, consonants.size() - 1);
    PrintArr(vowel);
    PrintArr(consonants);
}
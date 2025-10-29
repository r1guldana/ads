#include <bits/stdc++.h>
using namespace std;
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

        stable_sort(arr.begin(), arr.end(), [](const string& a,const string& b)
             { return a.size() < b.size(); });

        for (long long num = 0; num < arr.size(); num++)
            cout << arr[num] << " ";
        cout << endl;
    }
    return 0;
}
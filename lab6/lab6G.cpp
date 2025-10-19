#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, string> account;

    map<string, string> forward;
    map<string, string> reverse;

    for (int i = 0; i < n; i++)
    {
        string old_name, new_name;
        cin >> old_name >> new_name;
        if (reverse.count(old_name))
        {
            string org = reverse[old_name];
            forward[org] = new_name;
            reverse.erase(old_name);
            reverse[new_name] = org;
        }
        else
        {
            forward[old_name] = new_name;
            reverse[new_name] = old_name;
        }
    }
    cout << forward.size() << endl;
    for (map<string, string>::iterator it = forward.begin();
         it != forward.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

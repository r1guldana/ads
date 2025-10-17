#include <bits/stdc++.h>
#include <sstream>
using namespace std;
struct Date
{
    int day, month, year;
};
bool compare(const Date &d1, const Date &d2)
{
    if (d1.year < d2.year)
        return true;
    if (d1.year == d2.year && d1.month < d2.month)
        return true;
    if (d1.year == d2.year && d1.month == d2.month &&
        d1.day < d2.day)
        return true;

    return false;
}
void quick_sort(vector<Date> &a, int l, int r)
{
    if (l >= r)
        return;
    Date mid = a[(l + r) / 2];
    int i = l;
    int j = r;

    while (i <= j)
    {
        while (compare(a[i], mid)) // compare(a[i]< mid)
            i++;
        while (compare(mid, a[j]))
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quick_sort(a, l, j);
    if (i < r)
        quick_sort(a, i, r);
}
int main()
{
    int n;
    cin >> n;
    vector<Date> dates;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        //  DD-MM-YYYY
        int day = (s[0] - '0') * 10 + (s[1] - '0');
        int month = (s[3] - '0') * 10 + (s[4] - '0');
        int year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 +
                   (s[8] - '0') * 10 + (s[9] - '0');
        Date d;
        d.day = day;
        d.month = month;
        d.year = year;
        dates.push_back(d);
    }
    if (!dates.empty())
    {
        quick_sort(dates, 0, dates.size() - 1);
    }
    for (int i = 0; i < dates.size(); i++)
    {
        if (dates[i].day < 10)
            cout << "0";
        cout << dates[i].day << "-";

        if (dates[i].month < 10)
            cout << "0";
        cout << dates[i].month << "-";

        cout << dates[i].year << endl;
    }
}

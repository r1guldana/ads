#include <bits/stdc++.h>
using namespace std;

pair<string, double> grade_array[] = {
    make_pair("A+", 4.00), make_pair("A", 3.75), make_pair("B+", 3.50),
    make_pair("B", 3.00), make_pair("C+", 2.50), make_pair("C", 2.00),
    make_pair("D+", 1.50), make_pair("D", 1.00), make_pair("F", 0.00)};
vector<pair<string, double> > grade_scale(grade_array, grade_array + 9);

double get_gpa_value(const string &mark)
{
    for (int i = 0; i < grade_scale.size(); ++i)
    {
        if (grade_scale[i].first == mark)
            return grade_scale[i].second;
    }
    return 0.0;
}

struct Student
{
    string lastname, firstname;
    double gpa;
};

bool compare(const Student &a, const Student &b)
{
    if (a.gpa != b.gpa)
        return a.gpa < b.gpa;
    if (a.lastname != b.lastname)
        return a.lastname < b.lastname;
    return a.firstname < b.firstname;
}

void quick_sort(vector<Student> &a, int l, int r)
{
    if (l >= r)
        return;
    Student pivot = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j)
    {
        while (compare(a[i], pivot))
            i++;
        while (compare(pivot, a[j]))
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
    vector<Student> students;

    for (int i = 0; i < n; ++i)
    {
        string lastname, firstname;
        int m;
        cin >> lastname >> firstname >> m;

        double total_points = 0.0, total_credits = 0.0;
        for (int j = 0; j < m; ++j)
        {
            string mark;
            int credit;
            cin >> mark >> credit;
            total_points += get_gpa_value(mark) * credit;
            total_credits += credit;
        }

        double gpa = (total_credits > 0) ? total_points / total_credits : 0.0;

        Student s;
        s.lastname = lastname;
        s.firstname = firstname;
        s.gpa = gpa;
        students.push_back(s);
    }

    if (!students.empty())
    {
        quick_sort(students, 0, students.size() - 1);
    }

    for (int i = 0; i < students.size(); ++i)
    {
        cout << students[i].lastname << " " << students[i].firstname << " ";
        cout << fixed << setprecision(3) << students[i].gpa << endl;
    }

    return 0;
}
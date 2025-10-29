#include <bits/stdc++.h>
using namespace std;
struct student{
    string f_name;
    string l_name;
    int subjects;
    double gpa;
};

bool compare(const student &a, const student &b){
    if (a.gpa != b.gpa)
        return a.gpa < b.gpa;
    if (a.l_name != b.l_name)
        return a.l_name < b.l_name;
    return a.f_name< b.f_name;
}
void merge(vector<student> &a, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<student> L(n1), R(n2);
    for (int i = 0; i < n1; i++){
        L[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = a[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (compare(L[i], R[j])){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        a[k] =R[j];
        j++;
        k++;
    }
}
void merge_sort(vector<student> &a, int l, int r){
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, mid, r);
}
double gpa( const string &grade){
    if (grade == "A+") return 4.0;
    if (grade == "A") return 3.75;
    if (grade == "B+") return 3.5;
    if (grade == "B") return 3.0;
    if (grade == "C+") return 2.5;
    if (grade == "C") return 2.0;
    if (grade == "D+") return 1.5;
    if (grade == "D") return 1.0;
    if (grade == "F") return 0.0;
    return 0.0;
}
int main(){
    int n;
    cin >> n;
    vector<student> list;
    for (int i = 0; i < n; i++)
    {
        string first , second;
        int subs;
        student st;
        cin >> second>> first>> subs ;
        st.l_name = second;
        st.f_name = first;
        double total = 0.0;
        int credits = 0;
        for(int j = 0 ; j< subs; j++){
            string grade;
            int credit;
            cin >> grade >> credit;
            double g =gpa(grade);
            total += credit * g;
            credits+= credit;
        }
            st.gpa = total/credits;
            list.push_back(st); 
    }
    if(!list.empty()){
        merge_sort(list, 0 , n-1);
    }
    for (int i = 0; i < list.size(); i++)
    {
        cout<<list[i].l_name<<" "<< list[i].f_name<<" "
        <<fixed << setprecision(3) << list[i].gpa << endl;
    }
    return 0;
}
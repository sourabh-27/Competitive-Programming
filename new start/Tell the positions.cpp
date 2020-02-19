#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
struct Student
{
    string name;
    int roll;
    int total;
};


bool Compare(Student a, Student b)
{
    if(a.total != b.total)
    {
        return a.total > b.total;
    }
    else
    {
        return a.roll < b.roll;
    }
    
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    Student a[n];
    int x, y, z, marks;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].name;
        cin >> x >> y >> z;
        marks = x + y + z;
        a[i].roll = i;
        a[i].total = marks;
    }
    sort(a, a+n, Compare);
    int j = 1;
    for(int i = 0; i < n; i++)
    {
        cout << j << " " << a[i].name << endl;
        j++; 
    }
}
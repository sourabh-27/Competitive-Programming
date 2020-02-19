#include<bits/stdc++.h>
using namespace std;

struct s{
    string name;
    int total;
};

bool compare(s s1, s s2)
{
    if(s1.total == s2.total)
    {
        return s1.name > s2.name;
    }
    else
    {
        return s1.total > s2.total;
    }
    
}

int main()
{
    int size;
    cin >> size;
    struct s arr[size];
    for(int i = 0; i < size; i++){
        string str;
        cin >> str;
        arr[i].name = str;
        int m1, m2, m3;
        cin >> m1 >> m2 >> m3;
        arr[i].total = m1 + m2 + m3;
    }

    sort(arr, arr + size, compare);
    for(int i = 0; i < size; i++)
    {
        cout << i + 1 << " " << arr[i].name << endl;
    }
    
	return 0;
}

#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int len = s.length();
    bool *visited = new bool[201];
    for(int i = 0; i < 200; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(!visited[(int)s[i]])
        {
            count++;
            visited[(int)s[i]] = true;
        }
    }

    if(count % 2 == 0)
    {
        cout << "CHAT WITH HER!";
    }
    else
    {
        cout << "IGNORE HIM!";
    }
    

    return 0;
}
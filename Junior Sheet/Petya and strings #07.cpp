#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char s1[100];
    cin >> s1;
    char s2[100];
    cin >> s2;
    int m = strlen(s1);
    int n = strlen(s2);
    for(int i = 0; i < m; i++)
    {
        s1[i] = toupper(s1[i]);
    }

    for(int i = 0; i < n; i++)
    {
        s2[i] = toupper(s2[i]);
    }

    // cout << s1 << endl;
    // cout << s2;
    
    if(strcmp(s1, s2) == 0)
    {
        cout << 0 << endl;
    }
    else if(strcmp(s1, s2) < 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
    
    

    return 0;
}
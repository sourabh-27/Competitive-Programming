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
    int m = s.length();
    int upper = 0, lower = 0;
    for(int i = 0; i < m; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            upper++;
        }
        else
        {
            lower++;
        } 
    }

    if(upper > lower)
    {
        for(int i = 0; i < m; i++)
        {
            s[i] = toupper(s[i]);
        }
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            s[i] = tolower(s[i]);
        }
    }

    cout << s << endl;
    

    return 0;
}
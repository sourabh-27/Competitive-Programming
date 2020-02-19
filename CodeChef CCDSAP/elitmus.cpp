#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        ll len = s.length();
        for(ll i = len - 1; i >= 1; i--)
        {
            if(s[i] != '9' && s[i - 1] == '9')
            {
                continue;
            }
            else if(s[i] == )
        }
    }

    return 0;
}
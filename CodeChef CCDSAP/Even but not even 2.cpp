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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        string final = "";
        for(ll i = 0; i < n; i++)
        {
            if((s[i] - 48) % 2 != 0)
            {
                final += s[i];
                if(final.length() == 2)
                {
                    break;
                }
            }
        }
        if(final.length() < 2)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << final << endl;
        }
    }

    return 0;
}
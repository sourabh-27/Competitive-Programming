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
        string s;
        cin >> n;
        cin >> s;
        ll count = 0;
        for(ll i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                count++;
            }
        }
        cout << (count * (count + 1)) / 2 << endl;
    }

    return 0;
}
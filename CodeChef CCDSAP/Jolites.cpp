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
        ll count = 0;
        for(ll i = 0; i < n - 3; i++)
        {
            if(s[i] == 'J' && s[i + 1] == 'G' && s[i + 2] == 'E' && s[i + 3] == 'C')
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
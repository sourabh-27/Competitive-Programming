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
        n = n - 1;
        string s, ans;
        cin >> ans;
        while(n--)
        {
            cin >> s;
            for(ll i = 0; i < 10; i++)
            {
                // cout << (int)s[i] - 48 << " ";
                ans[i] = ((int)s[i] - 48) ^ ((int)ans[i] - 48) + 48;
                // cout << ans[i] << " ";
            }
            // cout << endl;
        }
        ll count = 0;
        for(ll i = 0; i < 10; i++)
        {
            if(ans[i] == '1')
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
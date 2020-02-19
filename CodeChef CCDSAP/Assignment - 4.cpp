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
        ll ones = n / 2;
        ll rem = n % 2;
        string ans = "";
        for(ll i = 0; i < ones; i++)
        {
            ans += '1';
        }
        if(rem == 1)
        {
            ans[0] = '7';
        }
        cout << ans << endl;
    }

    return 0;
}
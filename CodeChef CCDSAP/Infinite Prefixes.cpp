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
        ll n, x;
        cin >> n >> x;
        string str;
        cin >> str;
        long long dp[n + 1];
        ll points; ll zCount = 0, oCount = 0;
        for(ll i = 0; i < n; i++)
        {
            if(str[i] == '0')
            {
                zCount++;
            }
            else
            {
                oCount++;
            }
            points = zCount - oCount;
            dp[i] = points;
        }
        // there will be generally three cases when the 
        // for(ll i = 0; i  < n; i++)
        // {
        //     cout << dp[i] << " ";
            
        // }
        // cout << endl;
        if(points == 0 && x == 0)
        {
            cout << -1 << endl;
        }
        else if(x == 0)
        {
            ll ans = 1;
            for(ll i = 0; i < n; i++)
            {
                if(dp[i] == 0)
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
        else if((points >= 0 && x < 0) || (points <= 0 && x > 0))
        {
            ll ans = 0;
            for(ll i = 0; i < n; i++)
            {
                if(dp[i] == x)
            }
        }
    }

    return 0;
}
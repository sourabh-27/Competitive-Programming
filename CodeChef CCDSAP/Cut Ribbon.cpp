#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll dp[100000];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    for(ll i = 1; i <= n; i++)
    {
        dp[i] = -200000000000;
    }
    dp[0] = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(i >= a)
        {
            dp[i] = dp[i - a] + 1;
        }
        if(i >= b)
        {
            dp[i] = max(dp[i - b] + 1, dp[i]);
        }
        if(i >=c)
        {
            dp[i] = max(dp[i - c] + 1, dp[i]);
        }
        // cout << "i: " << i << " dp[i]: " << dp[i] << endl; 
    }
    cout << dp[n] << endl;

    return 0;
}
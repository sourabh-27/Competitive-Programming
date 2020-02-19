#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll dp[102];
    dp[1] = 1;
    dp[2] = 4;
    for(ll i = 3; i <= 100; i++)
    {
        dp[i] = 4 + dp[i - 1];
    }  

    ll ans = 0;
    for(ll i = 1; i <= n; i++)
    {
        ans += dp[i];
    }
    cout << ans << endl;

    return 0;
}
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
        ll n, p, k;
        cin >> n >> p >> k;
        ll arr[n + 2];
        for(ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        sort(arr + 1, arr + n + 1);
        ll dp[n + 3] = {0};
        for(ll i = 1; i <= n; i++)
        {
            if(i < k)
            {
                dp[i] = dp[i - 1] + arr[i];
            }
            else
            {
                dp[i] = dp[i - k] + arr[i];
            }
        }
        ll ans = 0;
        for(ll i = n; i > 0; i--)
        {
            if(dp[i] <= p)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
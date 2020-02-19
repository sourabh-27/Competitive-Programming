#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

const int N = 1000010;

long long dp[N]; int hash2[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    // ll arr[n + 1];
    memset(hash2, 0, sizeof(hash2));
    for(ll i = 0; i < n; i++)
    {
        // cin >> arr[i];
        ll k;
        cin >> k;
        hash2[k]++;
    }

    dp[0] = 0;
    for(ll i = 1; i < N; i++)
    {
        dp[i] =(long long) i * hash2[i];
        if(i - 2 >= 0)
        {
            dp[i] += dp[i - 2];
        }
        if(dp[i - 1] > (dp[i]))
        {
            dp[i] = dp[i - 1];
        }
        // cout << "dp[" << i << "]: " << dp[i] << endl;
    }
    cout << dp[N - 1] << endl;

    return 0;
}
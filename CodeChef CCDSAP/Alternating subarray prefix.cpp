#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long dp[n + 1];
        for(ll i = 0; i <= n; i++)
        {
            dp[i] = 1;
        }
        for(ll i = n - 2; i >= 0; i--)
        {
            if(arr[i] * arr[i + 1] < 0)
            {
                dp[i] = dp[i + 1] + 1;
            }
            else
            {
                dp[i] = 1;
            }
            
        }

        for(ll i = 0; i < n; i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
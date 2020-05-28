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
    while(t--){
        ll n;
        cin >> n;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        long long dp[n + 1];
        for(ll i = 0; i < n; i++){
            dp[i] = 0;
        }

        for(ll i = 1; i < n; i++){
            if(arr[i] < arr[i - 1]){
                ll diff = arr[i - 1] - arr[i];
                ll x = ceil(log2l(diff));
                x = x + 1;
                arr[i] += pow(2, x - 1);
                // cout << "arr[i]: " << arr[i] << endl;
                // dp[i] = (x - dp[i - 1]);
                dp[i] = x;
            }
        }

        for(ll i = 0; i < n; i++){
            cout << dp[i] << " ";
        }

        ll maxi = LONG_MIN; ll flag = 0; ll ans = 0;
        cout << "maxi: " << maxi << endl;
        stack<ll> st;
        for(ll i = 0; i < n; i++){
            if(dp[i] != 0){

                
            }
        }
        cout << ans << endl;
    }


    return 0;
}
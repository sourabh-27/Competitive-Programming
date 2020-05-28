#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll LIS(long long * arr, ll n, long long * dp){
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < i - 1; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long * arr = new long long [n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    //LIS is that strictly ends at i
    long long *dp = new long long[n + 1];
    for(ll i = 0; i < n; i++){
        dp[i] = 1;
    }
    ll ans = LIS(arr, n, dp);
    ll maxi = INT_MIN;
    for(ll i = 0; i < n; i++){
        maxi = max(maxi, dp[i]);
    }
    cout << "LIS: " << maxi << endl;

    return 0;
}
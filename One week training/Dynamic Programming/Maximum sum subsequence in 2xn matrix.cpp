#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll findMaxSum(long long ** arr, ll i, ll n, long long * dp){
    if(i >= n){
        return 0;
    }
    if(dp[i] != NULL){
        // cout << "dp[i]: " << dp[i] << endl;
        return dp[i];
    }
    ll ans = max(max(arr[0][i], arr[1][i]) + findMaxSum(arr, i + 2, n, dp), findMaxSum(arr, i + 1, n, dp));
    dp[i] = ans;
    return ans;
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long ** arr = new long long *[2];
    for(ll i = 0; i < 2; i++){
        arr[i] = new long long *[n + 1];
    }
    for(ll i = 0; i < 2; i++){
        for(ll j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    long long *dp = new long long[n + 1];
    for(ll i = 0; i <= n; i++){
        dp[i] = NULL;
    }

    ll ans = findMaxSum(arr, 0, n, dp);
    cout << "The maximum sum of subsequence whose elements are not consequtive is: " << ans << endl;

    return 0;
}
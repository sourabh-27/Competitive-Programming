#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll findMaxSum(long long * arr, ll i, ll n, long long * dp){
    if(i >= n){
        return 0;
    }
    if(dp[i] != NULL){
        // cout << "dp[i]: " << dp[i] << endl;
        return dp[i];
    }
    ll ans = max(arr[i] + findMaxSum(arr, i + 2, n, dp), findMaxSum(arr, i + 1, n, dp));
    dp[i] = ans;
    return ans;
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long *dp = new long long[n + 1];
    for(ll i = 0; i <= n; i++){
        dp[i] = NULL;
    }
    //the ans is in f[0] but if you do bottom up approach then ans is in f[n - 1]
    ll ans = findMaxSum(arr, 0, n, dp);
    cout << "The maximum sum of subsequence whose elements are not consequtive is: " << ans << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
ll findAns(long long * arr, ll start, ll end, long long ** dp){
    if(start > end){
        dp[start][end] = 0;
        return 0;
    }
    if(start == end){
        dp[start][end] = 1;
        return 1;
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }
    if(arr[start] == arr[end]){
        dp[start][end] = 2 + findAns(arr, start + 1, end - 1, dp);
        return dp[start][end];
    }
    else{
        dp[start][end] = max(findAns(arr, start + 1, end, dp), findAns(arr, start, end - 1, dp));
        return dp[start][end];
    }
}
 
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
        long long ** dp = new long long *[n + 1];
        for(ll i = 0; i < n; i++){
            dp[i] = new long long [n + 1];
            for(ll j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }
        ll ans = findAns(arr, 0, n - 1, dp);
        cout << "The length of the longest palindrome is: " << ans << endl;
    }
 
 
    return 0;
}
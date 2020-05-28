#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll distinctWaysToJump(ll n, long long * dp){
    if(n == 1){
        return n;
    }
    if(n == 2){
        return 2;
    }
    if(dp[n] != NULL){
        return dp[n];
    }   
    ll ans1 = distinctWaysToJump(n - 1, dp);
    ll ans2 = distinctWaysToJump(n - 2, dp);
    dp[n] = ans1 + ans2;
    return ans1 + ans2;
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long * dp = new long long[n + 1];
    memset(dp, NULL, sizeof(dp));
    ll ans = distinctWaysToJump(n, dp);
    cout << "The different ways to reach n'th stair is: " << ans << endl;

    return 0;
}
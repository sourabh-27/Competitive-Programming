#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll fib(ll n, long long * dp){
    if(n < 2){
        return n;
    }
    if(dp[n] != NULL){
        return dp[n];
    }
    ll ans1 = fib(n - 1, dp);
    ll ans2 = fib(n - 2, dp);
    dp[n] = ans1 + ans2;
    return ans1 + ans2;
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long dp[n + 1] = {NULL};
    ll ans = fib(n, dp);
    cout << "The n'th fibonacci numbers is: " << ans << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i= 0; i < n; i++){
        cin >> arr[i];
    }
    //product hoga for example a b c d agar a b ko consider kare then a + b + ab Now consider a b c ko consider kare toh c * (a + b + ab + 1) + (a + b + ab);
    //You can simply keep track of one variable instead of dp, so space reduced to O(1)
    long long dp[n + 1];
    dp[0] = arr[0];
    for(ll i = 1; i < n; i++){
        dp[i] = (dp[i - 1] + 1) * arr[i] + dp[i - 1];
    }
    cout << "The sum of all subsequence is: " << dp[n - 1] << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

bool findAns(ll x, ll n, ll m, bool ** dp){
    // cout << "x: " << x << endl;
    if(x <= 0){
        dp[n][m] = true;
        return true;
    }
    if(dp[n][m]){
        return true;
    }
    if(n == 0 && m > 0){
        dp[n][m] = findAns(x - 10, n, m - 1, dp);
        return dp[n][m];
    }
    if(n > 0 && m == 0){
        dp[n][m] = findAns(floor(x / 2) + 10, n - 1, m, dp);
        return dp[n][m];
    }
    else if(n == 0 && m == 0){
        dp[n][m] = false;
        return false;
    }
    else{
        dp[n][m] = findAns(floor(x / 2) + 10, n - 1, m, dp) || findAns(x - 10, n, m - 1, dp);
        return dp[n][m];
    }
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll x, n, m;
        cin >> x >> n >> m;
        bool ** dp = new bool*[n + 1];
        for(ll i = 0; i <= n; i++){
            dp[i] = new bool[m + 1];
            for(ll j = 0; j <= m; j++){
                dp[i][j] = false;
            }
        }
        bool ans = findAns(x, n, m, dp);
        if(ans){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }


    return 0;
}
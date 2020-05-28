#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

bool findAns(ll x, ll n, ll maxM, bool * dp){
    // cout << "x: " << x << endl;
    if(x <= 0 || x <= maxM){
        dp[n] = true;
        return true;
    }
    else if(n <= 0){
        return false;
    }
    else{
        dp[n] = findAns(floor(x / 2) + 10, n - 1, maxM, dp);
        return dp[n];
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
        ll maxM = 10 * m;
        bool * dp = new bool[n + 1];
        for(ll i = 0; i <= n; i++){
            dp[i] = false;
        }
        bool ans = findAns(x, n, maxM, dp);
        if(ans){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }


    return 0;
}
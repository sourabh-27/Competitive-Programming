#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll LPS(string str, ll i, ll j, long long ** dp){
    if(i > j){
        return 0;
    }
    if(i == j){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(str[i] == str[j]){
        ll ans = 2 + LPS(str, i + 1, j - 1, dp);
        dp[i][j] = ans;
        return ans;
    }
else{
        ll ans1 = LPS(str, i + 1, j, dp);
        ll ans2 = LPS(str, i, j - 1, dp);
        dp[i][j] = max(ans1, ans2);
        return max(ans1, ans2);
    }
}
 
int main()
{
    fast;
    string str1;
    cin >> str1;
    ll len = str1.length();
    long long ** dp = new long long *[len + 1];
    for(ll i = 0; i <= str1.length(); i++){
        dp[i] = new long long[len + 1];
        for(ll j = 0; j <= len; j++){
            dp[i][j] = -1;
        }
    }
    ll ans = LPS(str1, 0, len - 1, dp);
    cout << "The length of longest palindromic subsequence: " << ans << endl;

    return 0;
}
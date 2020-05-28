#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll LCS(string str1, string str2, ll i, ll j, long long ** dp){
    if(i < 0 || j < 0){
        return 0;
    }

    if(str1[i] == str2[j]){
        dp[i][j] =  1 + LCS(str1, str2, i - 1, j - 1, dp);
        return dp[i][j];
    }
    else{
        ll ans1 = LCS(str1, str2, i, j - 1, dp);
        ll ans2 = LCS(str1, str2, i - 1, j, dp);
        dp[i][j] = max(ans1, ans2);
        return max(ans1, ans2);
    }
}
 
int main()
{
    fast;
    string str1, str2;
    cin >> str1 >> str2;
    long long ** dp = new long long *[str1.length() + 1];
    for(ll i = 0; i <= str1.length(); i++){
        dp[i] = new long long[str2.length() + 1];
    }
    ll ans = LCS(str1, str2, str1.length() - 1, str2.length() - 1, dp);
    cout << "LCS is: " << ans << endl;

    return 0;
}
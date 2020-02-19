#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll len = s.length();
    ll dp[len + 1] = {0}; ll totalQ = 0;
    for(ll i = 0; i < len; i++)
    {
        totalQ += (s[i] == 'Q') ? 1 : 0;
    }
    // cout << "totalQ: " << totalQ << endl;
    dp[0] = (s[0] == 'Q') ? 1 : 0;
    ll count = 0;
    for(ll i = 1; i < len; i++)
    {
        dp[i] = dp[i - 1];
        if(s[i] == 'A')
        {
            count += dp[i] * (totalQ - dp[i]);
        }
        else if(s[i] == 'Q')
        {
            dp[i]++;
        }
    }
    cout << count << endl;

    return 0;
}
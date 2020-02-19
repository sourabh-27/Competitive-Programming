#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        ll len = s.length();
        long long arr[100] = {0};
        for(ll i = 0; i < len; i++)
        {
            arr[s[i] - 'a']++;
        }
        string ans;
        for(ll i = 0; i < 27; i++)
        {
            for(ll j = 0; j < arr[i]; j++)
            {
                char c = i + 'a';
                ans += c;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}
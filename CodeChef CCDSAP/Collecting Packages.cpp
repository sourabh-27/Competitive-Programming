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
        ll n;
        cin >> n;
        vector<pair<ll, ll>> vec;
        for(ll i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            vec.push_back(make_pair(x, y));
        }

        string ans; ll actual = 0;
        sort(vec.begin(), vec.end());
        ll temp1 = vec[0].first; ll temp2 = vec[0].second;
        // cout << "temp1 : " << temp1 << " temp2 " << temp2 << endl;
        actual += temp1 + temp2; 
        while(temp1--)
        {
            ans = ans + 'R';
        }
        while(temp2--)
        {
            ans = ans + 'U';
        }
        for(ll i = 1; i < n; i++)
        {
            temp1 = vec[i].first - vec[i - 1].first;
            temp2 = vec[i].second - vec[i - 1].second;
            actual += temp1 + temp2;
            if(temp1 > 0)
            {
                while(temp1--)
                {
                    ans = ans + 'R';
                }
            }
            if(temp2 > 0)
            {
                while(temp2--)
                {
                    ans = ans + 'U';
                }
            }
        }
        // cout << "actual: " << actual << endl;
        if(ans == "" || ans.length() != actual)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << ans << endl;
        }
    }

    return 0;
}
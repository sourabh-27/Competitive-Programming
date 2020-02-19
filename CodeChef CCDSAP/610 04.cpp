#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool sortbysec(pair<ll, ll> &a, pair<ll, ll> &b) 
{ 
    return (a.second < b.second); 
} 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m;
    cin >> m;
    while(m--)
    {
        ll n, t, a, b;
        cin >> n >> t >> a >> b;
        ll arr[n + 1];
        vector<pair<ll, ll>> vec;
        ll easy = 0; ll hard = 0;
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] == 1)
            {
                hard++;
            }
            else
            {
                easy++;
            }
        }
        for(ll i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            pair<ll, ll> x;
            x.first = arr[i];
            x.second = k;
            vec.push_back(x);
        }
        vec.push_back({0, t + 1});
        sort(vec.begin(), vec.end(), sortbysec);
        ll count1 = 0, count2 = 0;
        ll ans = 0;
        for(ll i = 0; i <= n; i++)
        {
            ll req = a * count1 + b * count2;
            ll has = vec[i].second - 1 - req;
            // cout << "has: " << has << endl;
            if(has >= 0)
            {
                ll possibleA = min((easy - count1), has / a);
                has -= possibleA * a;
                ll possibleB = min((hard - count2), has / b);
                has -= possibleB * b;
                ans = max(ans, count1 + count2 + possibleB + possibleA);
            }

            ll update = i;
            while(update < vec.size() && vec[update].second == vec[i].second)
            {
                if(vec[update].first != 0)
                {
                    count2++;
                }
                else
                {
                    count1++;
                }
                update++;
            }
            i = update - 1;
        }
        cout << ans << endl;
    }

    return 0;
}
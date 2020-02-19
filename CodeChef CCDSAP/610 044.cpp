#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool sortBySec(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
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
        ll arr[n + 2];
        vector<pair<ll, ll>> vec;
        ll easy = 0, hard = 0;
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] == 0)
            {
                easy++;
            }
            else
            {
                hard++;
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
        sort(vec.begin(), vec.end(), sortBySec);
        ll count1 = 0, count2 = 0, ans = 0;
        for(ll i = 0; i <= n; i++)
        {
            ll required = count1 * a + count2 * b;
            ll has = vec[i].second - 1 - required;
            if(has >= 0)
            {
                ll eCount = min(easy - count1, has / a);
                has -= eCount * a;
                ll hCount = min(hard - count2, has / b);
                has -= hCount * b;
                ans = max(ans, count1 + count2 + eCount + hCount);
            }

            ll update = i;
            while(update <= n && vec[update].second == vec[i].second)
            {
                if(vec[update].first == 0)
                {
                    count1++;
                }
                else
                {
                    count2++;
                }
                update++;
            }
            i = update - 1;
        }
        cout << ans << endl;

    }

    return 0;
}
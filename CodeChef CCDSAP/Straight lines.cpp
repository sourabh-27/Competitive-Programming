#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
}
 
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
        long long xCor[100001] = {0}, yCor[100001] = {0};
        vector<pair<ll, ll>> vec;
        ll count = 0;
        for(ll i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            xCor[x]++; yCor[y]++;
            vec.push_back(make_pair(x, y));
        }
        for(ll i = 0; i < n; i++)
        {
            if(xCor[vec[i].first] == 1 && yCor[vec[i].second] == 1)
            {
                count++;
            }
        }
        cout << n - count << endl;
        // ll ans = nCr(n, 2);
        // cout << ans - n + count << endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool sortBySec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.second < b.second);
}

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p;
    ll x, y;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }

    sort(p.begin(), p.end(), sortBySec);

    // for(int i = 0; i < n; i++)
    // {
    //     cout << p[i].first << " " << p[i].second << endl;
    // }

    ll i = 0, count = 1;
    for(ll j = 1; j < n; j++)
    {
        if(p[j].first >= p[i].second)
        {
            count++;
            i = j;
        }
    }
    cout << count << endl;


    return 0;
}
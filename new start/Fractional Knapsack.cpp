#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void sortByFirst(const pair<pair<ll, ll>, ll> &a, const pair<pair<ll, ll>, ll> &b)
{
    if(a.first.first == b.first.first)
    {
        if(a.second == b.second)
        {
            return (a.first.second  < b.first.second);
        }
        return (a.second > b.second);
    }
    return (a.first.first < b.first.first);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, d;
    cin >> n >> d;
    vector<pair<pair<ll, ll>, ll>> p;
    ll a, b, c;
    for(ll i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        p.push_back(make_pair(make_pair(a, b), c));
    }

    sort(p.begin(), p.end(), sortByFirst);
    ll area = 0;
    ll bestSpeed = 0, cost = 0, lastTime = p[0].first.first;
    
    for(int i = 0; i < n; i++)
    {
        ll additional = bestSpeed * (p[i].first.first - lastTime);
        area = area  + additional;

        if(area >= d)
        {
            break;
        }

        if(p[i].second > bestSpeed)
        {
            bestSpeed = p[i].second;
            cost = cost + p[i].first.second;
        }
        lastTime = p[i].first.first;
    }
    cout << cost << endl;

    return 0;
}
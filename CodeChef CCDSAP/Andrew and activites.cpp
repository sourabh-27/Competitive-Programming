#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
  
ll activitesSelection(vector<ll> s, vector<ll> f)
{ 
    vector<pair<ll, ll>> ans; 
    priority_queue<pair<ll, ll>,vector<pair<ll, ll>>,greater<pair<ll, ll>>> pii; 
  
    for(ll i = 0; i < s.size(); i++)
    { 
        pii.push(make_pair(f[i], s[i])); 
    } 
  
    auto it = pii.top(); 
    ll starting = it.second; 
    ll ending = it.first; 
    pii.pop(); 
    ans.push_back(make_pair(starting, ending)); 
  
    while(!pii.empty())
    { 
        auto itr = pii.top(); 
        pii.pop(); 
        if(itr.second >= ending)
        { 
            starting = itr.second; 
            ending = itr.first; 
            ans.push_back(make_pair(starting, ending)); 
        } 
    }

    return ans.size();
} 
  
int main() 
{ 
    ll n;
    cin >> n;

    vector<ll> s;
    vector<ll> f;

    for(ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        s.push_back(x);
        f.push_back(y);
    }
    ll ans = activitesSelection(s, f);
    cout << ans << endl;
  
    return 0; 
} 
#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> graph[n + 1];
    for(ll i = 0; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[i].push_back(u);
        graph[v].push_back(v);
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void dfs(ll start, ll parent, ll * dist1, vector<ll> graph[])
{
    dist1[start] = dist1[parent] + 1;
    // cout << "I am currently at start: " << start << " and my parent is : " << parent << endl;
    for(ll i = 0; i < graph[start].size(); i++)
    {
        if(graph[start][i] == parent)
        {
            continue;
        }
        dfs(graph[start][i], start, dist1, graph);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, u, v;
    cin >> n >> u >> v;
    vector<ll> graph[n + 2];
    for(ll i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }


    ll dist1[n + 2], dist2[n + 2];
    dist1[0] = -1;
    dist2[0] = -1;

    dfs(u, 0, dist1, graph);
    dfs(v, 0, dist2, graph);

    ll maxi = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(dist2[i] > dist1[i])
        {
            maxi = max(maxi, dist2[i] - 1);
        }
    }
    cout << maxi << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void dfs(vector<ll> graph[], ll sV, bool * visited, ll & count)
{
    visited[sV] = true;
    // cout << "I am currently visiting: " << sV << endl;
    count++;
    for(ll i = 0; i < graph[sV].size(); i++)
    {
        if(!visited[graph[sV][i]])
        {
            dfs(graph, graph[sV][i], visited, count);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, p;
    cin >> n >> p;
    vector<ll> graph[n + 1];
    for(ll i = 0; i < p; i++)
    {
        ll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool * visited = new bool[n + 1];
    memset(visited, false, sizeof(visited));

    ll sum = 0; ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            ll count = 0;
            dfs(graph, i, visited, count);
            ans = ans + (sum) * count;
            sum += count;
        }
    }
    cout << ans << endl;

    return 0;
}
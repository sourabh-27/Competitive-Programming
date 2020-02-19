#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(vector<ll> graph[], ll sV, bool * visited)
{
    visited[sV] = true;
    for(ll i = 0; i < graph[sV].size(); i++)
    {
        if(!visited[graph[sV][i]])
        {
            dfs(graph, graph[sV][i], visited);
        }
    }
}

void addEdge(vector<ll> graph[], ll x, ll y)
{
    graph[x].push_back(y);
    graph[y].push_back(x);
}

int main()
{
    ll q;
    cin >> q;
    while(q--)
    {
        ll n, m, c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;
        vector<ll> graph[n + 1];
        for(ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            addEdge(graph, x, y);
        }

        bool * visited = new bool[n + 1];
        memset(visited, false, sizeof(visited));
        if(c_lib <= c_road)
        {
            cout << n * c_lib << endl;
        }
        else
        {
            ll count = 0;
            for(ll i = 1; i <= n; i++)
            {
                if(!visited[i])
                {
                    dfs(graph, i, visited);
                    ++count;
                    // cout << " count: " << count << endl;
                }
            }
            cout << ((c_road * (n - count)) + (c_lib * count)) << endl;
        }
    }
    return 0;
}

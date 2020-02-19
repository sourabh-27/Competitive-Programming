#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void DFSutil(vector<ll> graph[], ll sV, bool * visited)
{
    visited[sV] = true;
    for(ll i = 0; i < graph[sV].size(); i++)
    {
        if(!visited[graph[sV][i]])
        {
            DFSutil(graph, graph[sV][i], visited);
        }
    }
}

void addEdge(vector<ll> graph[], ll u, ll v)
{
    graph[u].push_back(v);
    // graph[v].push_back(u);
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
        ll n, m;
        cin >> n >> m;
        
        vector<ll> graph[n + 1];
        for(ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            addEdge(graph, u, v);
        }

        ll lastVisited = 0;
        bool visited[n];
        memset(visited, false, sizeof(visited));

        for(ll i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                // cout << "I am at i : " << i << endl;
                DFSutil(graph, i, visited);
                lastVisited = i;
            }
        }

        int flag = 0;
        fill(visited, visited + n, false);
        DFSutil(graph, lastVisited, visited);
        for(ll i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                flag = 1;
                break;
            }
        }
        // cout << "lastVisited: " << lastVisited << endl;

        if(flag == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << lastVisited << endl;
        }

    }

    return 0;
}
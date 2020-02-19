#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool hasPath(vector<ll> graph[], ll v, bool * visited, ll v1, ll v2)
{
    visited[v1] = true;
    if(v1 == v2)
    {
        return true;
    }
    for(ll i = 0; i < graph[v1].size(); i++)
    {
        if(!visited[graph[v1][i]])
        {
            if(hasPath(graph, v, visited, graph[v1][i], v2))
            {
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<ll> graph[], ll x, ll y)
{
    graph[x].push_back(y);
    graph[y].push_back(x);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll v, e;
    cin >> v >> e;
    vector<ll> graph[v + 1];
    for(ll i = 0; i < e; i++)
    {
        ll x, y;
        cin >> x >> y;
        addEdge(graph, x, y);
    }
    ll v1, v2;
    cin >> v1 >> v2;

    bool * visited = new bool[v + 1];
    memset(visited, false, sizeof(visited));

    bool ans = hasPath(graph, v, visited, v1, v2);
    if(ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
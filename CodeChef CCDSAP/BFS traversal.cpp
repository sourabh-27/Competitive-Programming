#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void addEdge(vector<ll> edges[], ll u, ll v)
{
    edges[u].push_back(v);
    edges[v].push_back(u);
}

void BFS(vector<ll> edges[], ll v, bool * visited, queue<ll> q)
{
    while(!q.empty())
    {
        ll s = q.front();
        cout << s << " ";
        q.pop();
        for(ll i = 0; i < edges[s].size(); i++)
        {
            if(!visited[edges[s][i]])
            {
                visited[edges[s][i]] = true;
                q.push(edges[s][i]);
            }
        }
    }
}

void printBFS(vector<ll> edges[], ll v)
{
    for(ll i = 0; i < v; i++)
    {
        cout << "I am in node " << i << endl;
        for(ll j = 0; j < edges[i].size(); j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll v, e;
    cin >> v >> e;

    vector<ll> edges[v];
    for(ll i = 0 ; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(edges, x, y);
    }

    printBFS(edges, v);

    bool * visited = new bool[v];
    memset(visited, false, sizeof(visited));
    queue<ll> q;
    q.push(0);
    visited[0] = true;

    BFS(edges, v, visited, q);
    

    return 0;
}
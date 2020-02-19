#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void addEdge(vector<ll> graph[], ll v, ll e)
{
    graph[v].push_back(e);
    graph[e].push_back(v);
}

ll DFSutil(vector<ll> graph[], ll n, ll sV, bool * visited, ll len)
{
    visited[sV] = true;
    if(sV == n)
    {
        cout << "I am currently at my destination with length: " << len << endl;
        return len;
    }
    for(ll i = 0; i < graph[sV].size(); i++)
    {
        if(!visited[graph[sV][i]])
        {
            cout << "I am currently visiting : " << graph[sV][i] << endl;
            len = len + 1;
            cout << "My curr length is : " << len << endl;
            DFSutil(graph, n, graph[sV][i], visited, len);
            len = len - 1;
        }
    }
    return len;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> graph[n + 1];
    for(ll i = 0; i < m; i++)
    {
        ll v, e;
        cin >> v >> e;
        addEdge(graph, v, e);
    }

    bool * visited = new bool[n + 1];
    memset(visited, false, sizeof(visited));

    ll len = 0;
    DFSutil(graph, n, 1, visited, 0);

    cout << len << endl;

    return 0;
}
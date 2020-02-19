#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void DFS(vector<ll> graph[], bool * visited, ll sV)
{
    visited[sV] = true;
    cout << sV << " ";
    for(ll i = 0; i < graph[sV].size(); i++)
    {
        if(!visited[graph[sV][i]])
        {
            DFS(graph, visited, graph[sV][i]);
        }
    }
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    ll e;
    cin >> e;
    vector<ll> graph[n + 1];
    for(ll i = 0; i < e; i++)
    {
        ll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool * visited = new bool[n + 1];
    memset(visited, false, sizeof(visited));

    for(ll i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            DFS(graph, visited, i);
        }
    }


    return 0;
}
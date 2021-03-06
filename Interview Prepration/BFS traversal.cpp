#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

void BFS(vector<ll> graph[], bool * visited, ll sV)
{
    visited[sV] = true;
    queue<ll> que;
    que.push(sV);
    while(!que.empty())
    {
        ll x = que.front();
        cout << x << " ";
        que.pop();
        for(ll i = 0; i < graph[x].size(); i++)
        {
            if(!visited[graph[x][i]])
            {
                que.push(graph[x][i]);
                visited[graph[x][i]] = true;
            }
        }
    }
}
 
int main()
{
    fast;
    ll n;
    cin >> n;
    vector<ll> graph[n + 1];
    ll e;
    cin >> e;
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
            BFS(graph, visited, i);
        }
    }

    return 0;
}
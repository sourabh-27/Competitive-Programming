#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void dfsUtil(ll sV, vector<ll> graph[], bool * visited)
{
    visited[sV] = true;
    // cout << "I am currently at sV" << sV << endl;
    for(ll i = 0; i < graph[sV].size(); i++)
    {
        if(!visited[graph[sV][i]])
        {
            dfsUtil(graph[sV][i], graph, visited);
        }
    }
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
        ll x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool * visited = new bool[n + 1];

    ll count = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            count++;
            // cout << "I am visiting " << i << endl;
            dfsUtil(i, graph, visited);
        }
    }

    cout << count << endl;

    return 0;
}
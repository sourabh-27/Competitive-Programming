#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll minDist(long long * dist, bool * visited, ll n)
{
    ll mini = INT_MAX, minIndex;
    for(ll i = 0; i < n; i++)
    {
        if(dist[i] <= mini && !visited[i])
        {
            minIndex = i;
            mini = dist[i];
            // cout << "minIndex: " << minIndex << " because mini is: " << mini << endl;
        }
    }
    return minIndex;
}

void printSol(long long * dist, ll n)
{
    for(ll i = 0; i < n; i++)
    {
        cout << i << dist[i] << endl;
    }
    return;
}

void dijkastra(long long ** graph, ll src, ll n)
{
    long long dist[n + 1];
    bool * visited = new bool[n + 1];
    memset(visited, false, sizeof(visited));
    for(ll i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    // printSol(dist, n);
    dist[src] = 0;

    for(ll i = 0; i < n - 1; i++)
    {
        ll u = minDist(dist, visited, n);
        visited[u] = true;  
        // cout << "I got min distance to: " << u << endl;
        for(ll j = 0; j < n; j++)
        {
            if(!visited[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    printSol(dist, n);
}
 
int main()
{
    fast;
    ll n, e;
    cin >> n >> e;
    long long ** graph = new long long *[n + 1];
    for(ll i = 0; i <= n; i++)
    {
        graph[i] = new long long[n + 1];
        for(ll j = 0; j <= n; j++)
        {
            graph[i][j] = 0;
        }
    }

    for(ll i = 0; i < e; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = z;
        graph[y][x] = z;
    }

    // for(ll i = 0; i < n; i++)
    // {
    //     for(ll j = 0; j < n; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    dijkastra(graph, 0, n);
    return 0;
}
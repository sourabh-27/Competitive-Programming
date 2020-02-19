#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void BFS(ll ** matrix, ll v, bool * visited, queue<ll> q)
{
    while(!q.empty())
    {
        ll x = q.front();
        visited[x] = true;
        cout << x << " ";
        q.pop();
        for(ll i = 0; i < v; i++)
        {
            if(matrix[x][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll v, e;
    cin >> v >> e;
    ll ** matrix = new ll*[v] + 1;
    for(ll i = 0; i <= v; i++)
    {
        matrix[i] = new ll[v + 1];
        for(ll j = 0; j <= v; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for(ll i = 0; i < e; i++)
    {
        ll x, y;
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }

    bool * visited = new bool[v];
    memset(visited, false, sizeof(visited));
    queue<ll> q;
    q.push(0);
    BFS(matrix, v, visited, q);

    return 0;
}
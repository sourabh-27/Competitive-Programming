#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

vector<ll> arr;
void bfs(vector<ll> graph[], bool * visited, ll sV)
{
    visited[sV] = true;
    queue<ll> q;
    cout << "I am currently at: " << sV << endl;
    q.push(sV);
    while(!q.empty())
    {
        ll s = q.front();
        q.pop();
        for(ll i = 0; i < graph[sV].size(); i++)
        {
            // cout << "I am trying to check: " << graph[sV][i] << endl;
            if(!visited[graph[sV][i]] && arr[graph[sV][i]] == -1)
            {
                cout << "I am going to visit: " << graph[sV][i] << endl;
                arr[graph[sV][i]] = arr[sV] + 1;
                cout << "arr[sV]: " << arr[sV] << endl;
                visited[graph[sV][i]] = true;
                q.push(graph[sV][i]);
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin >> q;
    while(q--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> graph[n + 1];
        for(ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            graph[x - 1].push_back(y - 1);
            graph[y - 1].push_back(x - 1);
        }
        ll sV;
        cin >> sV;
        arr.resize(n, -1);
        bool * visited = new bool[n + 1];
        memset(visited, false, sizeof(visited));

        arr[sV] = 0;
        bfs(graph, visited, sV - 1);
        for(ll i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                bfs(graph, visited, i);
            }
        }

        for(ll i = 0; i < arr.size(); i++)
        {
            // if(arr[i] == -1)
            // {
            //     cout << -1 << " ";
            // }
            // else if(arr[i] != 0)
            // {
            //     cout << arr[i] * 6 << " ";
            // }
            cout << arr[i] << " ";
        }
        cout << endl;
        arr.clear();
    }

    return 0;
}
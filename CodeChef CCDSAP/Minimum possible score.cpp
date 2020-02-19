#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll pGlobal = 0, mGlobal = 0, neutral = 0;
ll pCount = 0, mCount = 0;
void DFS(vector<ll> graph[], bool * visited, ll sV, char * arr)
{
    visited[sV] = true;
    // cout << "I am visiting: " << sV << endl;
    if(arr[sV - 1] == 'M')
    {
        mCount += 1;
    }
    else
    {
        pCount += 1;
    }
    for(ll i = 0; i < graph[sV].size(); i++)
    {
        if(!visited[graph[sV][i]])
        {
            DFS(graph, visited, graph[sV][i], arr);
        }
    }
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
        ll n, k;
        cin >> n >> k;
        char arr[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> graph[n + 1];
        for(ll i = 0; i < k; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool * visited = new bool[n + 1];
        memset(visited, false, sizeof(visited));

        for(ll i = 1; i < n; i++)
        {
            if(!visited[i])
            {
                // cout << "I am going to visit: " << i << endl;
                DFS(graph, visited, i, arr);
                // cout << "mCount " << mCount << " pCount: " << pCount << endl;
                if(pCount > mCount)
                {
                    pGlobal += 1;
                }
                else if(mCount > pCount)
                {
                    mGlobal += 1;
                }
                else
                {
                    neutral += 1;
                }
            }
            pCount = 0; mCount = 0;
        }

        cout << pGlobal << " " << mGlobal << " " << neutral << endl;

        
    }

    return 0;
}
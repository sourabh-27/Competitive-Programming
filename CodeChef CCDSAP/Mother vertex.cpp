#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void DFSutil(vector<ll> vec[], ll v, ll sV, ll &size, bool * visited)
{
    // cout << "I am in : " << sV << endl;
    for(ll i = 0; i < vec[sV].size(); i++)
    {
        if(!visited[vec[sV][i]])
        {
            // cout << "I am in i: " << i << " and aage ka value: " << vec[sV][i] << endl;
            size = size + 1;
            visited[vec[sV][i]] = true;
            DFSutil(vec, v, vec[sV][i], size, visited);
        }
    }
}

ll DFSmotherVertex(vector<ll> vec[], ll v, bool * visited)
{
    for(ll i = 0; i < v; i++)
    {
        ll size = 1;
        visited[i] = true;
        DFSutil(vec, v, i, size, visited);
        // cout << "My sv is : " << i << " and the size I am returing is : " << size << endl;
        if(size == v)
        {
            return i;
        }
        memset(visited, false, sizeof(visited));
    }
    return -1;
}

void printList(vector<ll> vec[], ll v)
{
    for(ll i = 0; i < v; i++)
    {
        for(ll j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

void addEdge(vector<ll> vec[], ll x, ll y)
{
    vec[x].push_back(y);
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
        ll v, e;
        cin >> v >> e;

        vector<ll> vec[v + 1];

        for(ll i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            addEdge(vec, x, y);
        }

        // printList(vec, v);

        bool * visited = new bool[v + 1];
        memset(visited, false, sizeof(visited));

        ll ans;
        ans = DFSmotherVertex(vec, v, visited);
        delete[] visited;
        cout << ans << endl;
    }
    return 0;
}
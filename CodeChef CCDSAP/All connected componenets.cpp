#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

set<int> s;
set<int>::iterator itr;
void DFS(int ** edges, int v, bool * visited, int sV)
{
    visited[sV] = true;
    s.insert(sV);
    for(int i = 0; i < v; i++)
    {
        if(edges[sV][i] == 1 && !visited[i])
        {
            DFS(edges, v, visited, i);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, e;
    cin >> v >> e;
    int ** edges = new int*[v + 1];
    for(int i = 0; i <= v; i++)
    {
        edges[i] = new int[v + 1];
        for(int j = 0; j <= v; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    bool * visited = new bool[v + 1];
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            DFS(edges, v, visited, i);
            for(itr = s.begin(); itr != s.end(); itr++)
            {
                cout << *itr << " ";
            }
            cout << endl;
            s.clear();
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void DFS(int ** edges, int n, int sv, bool * visited)
{
    visited[sv] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i])
        {
            DFS(edges, n, i, visited);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, e;
    cin >> n >> e;
    int ** edges = new int *[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool * visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    DFS(edges, n, 0, visited);
    
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            flag = 1;
        }
    }

    if(flag)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }
    

    return 0;
}
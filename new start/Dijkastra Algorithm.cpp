#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int * dist, bool * visited, int n)
{
    int minVertex = -1;
    for(int i = 0; i < n; i++)    
    {
        if(!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex]))
        {
            minVertex = i;
        }
    }
    
    return minVertex;
}

void dijkastra(int ** edges, int n)
{
    bool * visited = new bool[n];
    int * dist = new int[n];
    for(int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    
    for(int i = 0; i < n - 1; i++)
    {
        int minVertex = getMinVertex(dist, visited, n);
        visited[minVertex] = true;
        
        for(int j = 0; j < n - 1; j++)
        {
            if(edges[minVertex][j] && !visited[j])
            {
                int currD = dist[minVertex] + edges[minVertex][j];
                if(dist[j] > currD)
                {
                    dist[j] = currD;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
    delete[] visited;
    delete[] dist;
}

int main()
{
    int n, e;
    cin >> n >> e;
    
    int ** edges = new int * [n];
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
        int x, y, z;
        cin >> x >> y >> z;
        edges[x][y] = z;
        edges[y][x] = z;
    }
    
}
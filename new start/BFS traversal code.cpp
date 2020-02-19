#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void print(int ** edges, int n, bool * visited, queue<int> q)
{
    while(!q.empty())
    {
        int x = q.front();
        visited[x] = true;
        cout << x << " ";
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(edges[x][i] == 1 && visited[i] == false)
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
    queue<int> q;
    q.push(0);
    print(edges, n, visited, q);

    return 0;
}
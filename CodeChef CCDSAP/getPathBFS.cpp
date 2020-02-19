#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int arr[1001] = {-1};

void BFS(int ** edges, int v, bool * visited, int y, queue<int> q)
{
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        visited[x] = true;
        for(int i = 0; i < v; i++)
        {
            if(edges[x][i] == 1 && !visited[i])
            {
                if(i == y)
                {
                    q.push(i);
                    arr[i] = x;
                    return;
                }
                q.push(i);
                arr[i] = x;
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

    int x, y;
    cin >> x >> y;

    bool * visited = new bool[v + 1];
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(x);

    BFS(edges, v, visited, y, q);

    if(arr[y] != -1 && y != -1)
    {
        cout << y << " ";
        while(true)
        {
            y = arr[y];
            cout << y << " ";
            if(y == x)
            {
                break;
            }
        }
    }


    return 0;
}
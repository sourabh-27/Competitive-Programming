#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int arr[1001];


void BFS(int ** edges, int n, int y, bool * visited, queue<int> q)
{
    while(!q.empty())
    {
        int x = q.front();
        visited[x] = true;
        q.pop();
        for(int i = 0; i < n; i++)
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
    int n, e;
    cin >> n >> e;
    int ** edges = new int*[n];
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

    int x, y;
    cin >> x >> y;
    
    
    for(int i = 0; i < 1000; i++)
    {
        arr[i] = -1;
    }
    queue<int> q;
    q.push(x);
    BFS(edges, n, y, visited, q);

    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    int z = y;
    // cout << "z:" << z << endl;
    // cout << "arr[z]: " << arr[z] << endl;
    if(z != -1)
    {
        cout << z << " ";
        while(true)
        {
            z = arr[z];
            cout << z << " ";
            if(z == x)
            {
                break;
            }
        }
    }

    return 0;
}
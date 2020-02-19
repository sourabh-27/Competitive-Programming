#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

vector<int> universal;

void pathFinder(int ** edges, int n, int x, int y, bool * visited)
{
    if(x == y)
    {
        cout << "x: " << x << endl;
        visited[y] = true;
        universal.push_back(x);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(i == x)
        {
            continue;
        }
        if(edges[x][i] == 1 && !visited[i])
        {
            visited[i] = true;
            pathFinder(edges, n, i, y, visited);
            if(!universal.empty() && i != y)
            {
                universal.push_back(i);
                return;
            }
        }
    }
    return;
    
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
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    bool * visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int x, y;
    cin >> x >> y;

    pathFinder(edges, n, x, y, visited);

    cout << "YO" << universal.size() << endl;
    for(int i = 0; i < universal.size(); i++)
    {
        cout << universal[i] << " ";
    }

    return 0;
}
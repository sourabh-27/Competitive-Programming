#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool checkDFS(int ** edges, int n, int x, int y, bool * visited)
{
    visited[x] = true;
    if(x == y)
    {
        return true;
    }
    for(int i = 0; i < n; i++)
    {
        if(i == x)
        {
            continue;
        }
        if(edges[x][i] == 1 && !visited[i])
        {
            if(checkDFS(edges, n, i, y, visited))
            {
                return true;
            }
        }
    }
    return false;
}

// bool check(int ** edges, int n, int x, int y)
// {
//     if(edges[x][y] == 1)
//     {
//         return true;
//     }
//     bool * visited = new bool[n];
//     for(int i = 0; i < n; i++)
//     {
//         visited[i] = false;
//     }

//     for(int i = 0; i < n; i++)
//     {
//         if(!visited[i])
//         {
//             if(checkDFS(edges, n, x, y, visited))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int x, y;
    cin >> x >> y;

    bool * visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    bool ans = checkDFS(edges, n, x, y, visited);
    if(ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
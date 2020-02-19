#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
vector<int> vec;

void pathFinder(int ** edges, int n, int x, int y, bool * visited)
{
    if(x == y)
    {
        vec.push_back(y);
        visited[x] = true;
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
            if(!vec.empty() && i != y)
            {
                vec.push_back(i);
                return;
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

    int x, y;
    cin >> x >> y;
    
    bool * visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    visited[x] = true;
    if(edges[x][y] == 1)
    {
        vec.push_back(y);
        vec.push_back(x);
    }
    else
    {
        pathFinder(edges, n, x, y, visited);
        if(!vec.empty() && vec.size() != 1)
        {
            vec.push_back(x);
        }
    }

    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}
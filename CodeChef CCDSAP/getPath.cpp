#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

vector<int> vec;
int flag = 0;

void getPath(int ** graph, int v, bool * visited, int x, int y)
{
    if(x == y)
    {
        // cout << "I have reached destination : " << x << endl;
        visited[x] = true;
        flag = 1;
        vec.push_back(y);
        return;
    }
    visited[x] = true;
    for(int i = 0; i < v; i++)
    {
        if(i == x)
        {
            continue;
        }
        if(graph[x][i] == 1 && !visited[i] && flag != 1)
        {
            // cout << "I am currently going to visit : " << i << endl;
            getPath(graph, v, visited, i, y);
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
    int v, e;
    cin >> v >> e;

    int ** graph = new int *[v + 1];
    for(int i = 0; i <= v; i++)
    {
        graph[i] = new int[v + 1];
        for(int j = 0; j <= v; j++)
        {
            graph[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;

    bool * visited = new bool[v + 1];
    memset(visited, false, sizeof(visited));

    visited[v1] = true;

    if(graph[v1][v2] == 1)
    {
        vec.push_back(v2);
        vec.push_back(v1);
    }
    else
    {
        getPath(graph, v, visited, v1, v2);
        if(!vec.empty() && vec.size() != 1)
        {
            vec.push_back(v1);
        }
    }
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
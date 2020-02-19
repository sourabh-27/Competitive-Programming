#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int ** edges, int n, bool * visited, int sv, int start, int goal, int & count)
{
    visited[sv] = true;
    // cout << "I am at vertex: " << sv << " and the value of goal is : " << goal << endl;
    if(goal == 0)
    {
        visited[sv] = false;
        if(edges[start][sv] == 1)
        {
            // cout << "YAAAAASS!!!" << endl;
            count++;
            return;
        }
        else
        {
            return;
        }  
    }

    for(int i = 1; i <= n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i])
        {
            DFS(edges, n, visited, i, start, goal - 1, count);
        }
    }
    visited[sv] = false;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int ** edges = new int*[n + 1];
    for(int i = 0; i <= n; i++)
    {
        edges[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        edges[u[i]][v[i]] = 1;
        edges[v[i]][u[i]] = 1;
    }

    bool * visited = new bool[n + 1];
    memset(visited, false, sizeof(visited));

    int count = 0;
    // cout << DFS(edges, n, visited, 1, 1, 2) << " yo " << endl;
    for(int i = 1; i <= n - 2; i++)
    {
        DFS(edges, n, visited, i , i, 2, count);
        visited[i] = true;
    }

    // cout <<  count << endl;
    return count/2;
}

int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
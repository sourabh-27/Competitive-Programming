#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// #include "solution.h"

bool DFS(int ** edges, int n, bool * visited, int sv, int start, int goal)
{
    visited[sv] = true;
    if(goal == 0)
    {
        if(edges[start][sv] == 1)
        {
            return true;
        }
        else
        {
            visited[sv] = false;
            return false;
        }  
    }

    for(int i = 0; i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i])
        {
            DFS(edges, n, visited, i, start, goal - 1);
        }
    }
    visited[sv] = false;
    return false;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int ** edges = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        edges[u[i]][v[i]] = 1;
        edges[v[i]][u[i]] = 1;
    }

    bool * visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(DFS(edges, n, visited, i , i, 3))
            {
                count++;
            }
        }
    }

    cout <<  count << endl;
    return count;
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
#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
// #include "solution.h"

bool search(char graph[][MAXN], string word, int i, int j, int index, int n, int m, bool ** visited)
{
    // cout << "I am at i:" << i << " j: " << j << "and index:" << index << endl;
    if(index == word.length())
    {
        return true;
    }
    if(i >= n || i < 0 || j >= m || j < 0 || graph[i][j] != word[index] || visited[i][j])
    {
        return false;
    }

    visited[i][j] = true;
    if( search(graph, word, i - 1, j - 1, index + 1, n, m, visited) || 
        search(graph, word, i - 1, j, index + 1, n, m, visited) || 
        search(graph, word, i - 1, j + 1, index + 1, n, m, visited) || 
        search(graph, word, i, j - 1, index + 1, n, m, visited) ||
        search(graph, word, i, j + 1, index + 1, n, m, visited) ||
        search(graph, word, i + 1, j - 1, index + 1, n, m, visited) ||
        search(graph, word, i + 1, j, index + 1, n, m, visited) ||
        search(graph, word, i + 1, j + 1, index + 1, n, m, visited))
    {
        return true;
    }

    visited[i][j] = false;
    return false;
}

bool exist(char graph[][MAXN], string word, int n, int m, bool ** visited)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(word[0] == graph[i][j] && search(graph, word, i, j, 0, n, m, visited))
            {
                return true;
            }
        }
    }

    return false;
}

int solve(char graph[][MAXN], int n, int m)
{
    bool ** visited = new bool *[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
    string word = "CODINGNINJA";
    if(exist(graph, word, n, m, visited))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}
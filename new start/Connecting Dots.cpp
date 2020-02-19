#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
// #include "solution.h"

bool cycle(char board[][MAXN], int n, int m, int index, int i, int j, bool ** visited, int start, int end, char find)
{
    if(index >= 4 && ((start == i + 1 && end == j) || (start == i && end == j - 1) || (start == i && end == j + 1) || (start == i - 1 && end == j)))
    {
        return true;
    }
    if(i >= n || i < 0 || j >= m || j < 0 || board[i][j] != find || visited[i][j])
    {
        return false;
    }
    visited[i][j] = true;
    if( cycle(board, n, m, index + 1, i - 1, j, visited, start, end, find) || 
        cycle(board, n, m, index + 1, i, j - 1, visited, start, end, find) || 
        cycle(board, n, m, index + 1, i, j + 1, visited, start, end, find) || 
        cycle(board, n, m, index + 1, i + 1, j, visited, start, end, find))
        {
            return true;
        }

    visited[i][j] = false;
    return false;
}

int solve(char board[][MAXN],int n, int m)
{
    bool ** visited = new bool * [n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(cycle(board, n, m, 0, i, j, visited, i, j, board[i][j]))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}
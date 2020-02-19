#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int board[21][21];

bool isPossible(int maze[20][20], int n, int x, int y)
{
    if(x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && board[x][y] != 1)
    {
        return true;
    }
    return false;
}


void path_finder(int maze[20][20], int n, int row, int col)
{
    if(row == n - 1 && col == n - 1)
    {
        board[n - 1][n - 1] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    if(isPossible(maze, n, row, col))
    {
        board[row][col] = 1;
        if(isPossible(maze, n, row + 1, col))
        {
            path_finder(maze, n, row + 1, col);
            if(isPossible(maze, n, row, col - 1))
            {
                path_finder(maze, n, row, col - 1);
            }
        }
        if(isPossible(maze, n, row, col + 1))
        {
            path_finder(maze, n, row, col + 1);
            if(isPossible(maze, n, row - 1, col))
            {
                path_finder(maze, n, row - 1, col);
            }
        }
        board[row][col] = 0;
    }
}

void ratInAMaze(int maze[20][20], int n)
{
    memset(board, 0, 21 * 21 * sizeof(int));
    path_finder(maze, n, 0, 0);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; 
    cin >> n ;
    int maze[20][20];
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n; j++){
                cin >> maze[i][j];
            }		
    }
    ratInAMaze(maze, n);

    return 0;
}
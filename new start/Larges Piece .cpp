#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];

int findLargest(char cake[NMAX][NMAX], int n, int i, int j, bool ** visited, int count)
{
    visited[i][j] = true;
    if(i <= n || i < 0 || j >= n || j < 0 || cake[i][j] != 1 || visited[i][j])
    {
        return count;
    }

    int ans1 = findLargest(cake, n, i - 1, j, visited, count + 1);
    int ans2 = findLargest(cake, n, i, j - 1, visited, count + 1);
    int ans3 = findLargest(cake, n, i, j + 1, visited, count + 1);
    int ans4 = findLargest(cake, n, i + 1, j, visited, count + 1);

    return ans1 + ans2 + ans3 + ans4;   
}
int solve(int n, char cake[NMAX][NMAX])
{
    bool ** visited = new bool * [n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(cake[i][j] == 1 && !visited[i][j])
            {
                maxi = max(findLargest(cake, n, i, j, visited, 0), maxi);
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        visited[i][j] = false;
                    }
                }
            }
        }
    }
    return maxi;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
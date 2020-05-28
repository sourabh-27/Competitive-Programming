#include <bits/stdc++.h>
using namespace std;

int A[100][100], DP[100][100];
int helper (int n,int m)
{
    
    if(n==0||m==0)
    {
        return 0;
    }
    if(DP[n][m]>-1)
    {
        return DP[n][m];
    }
    
    int x=A[n][m]+helper(n-1,m);
    int y=A[n][m]+helper(n-1,m+1);
    int z=A[n][m]+helper(n-1,m-1);
    DP[n][m]=min(x,min(y,z));
    
    return DP[n][m];
}



int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    
    // int DP[n+1][m+1];
    
    for(int i=0;i<=100;i++)
    {
         for(int j=0;j<=100;j++)
        {
            DP[i][j]=-1;
        }
    }
    
    int ans=helper(n,m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
    
    
    
    return 0;
    
}
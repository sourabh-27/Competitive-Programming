#include <bits/stdc++.h>
using namespace std;

int charilepilots(int a[],int c[],int x,int n,int **dp)
{
    if(n<=0)
    {
        return 1;
    }
    int ans;
    if(dp[n][x]>-1)
    {
        return dp[n][x];
    }
    if(x==0)
    {
        ans=a[0]+charilepilots(a+1,c+1,1,n-1,dp);
    }
    if(x==n)
    {
        ans=c[0]+charilepilots(a+1,c+1,x-1,n-1,dp);
    }

    else
    {
        ans=min(a[0]+charilepilots(a+1,c+1,x+1,n-1,dp),c[0]+charilepilots(a+1,c+1,x-1,n-1,dp));
    }
    dp[n][x]=ans;
    return dp[n][x];
}

int main()
{
    int n;
    cin>>n;
    int a[n],c[n];
    for(int i=0;i<n;i++)
    {
        cin>>c[i]>>a[i];
    }
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<n+1;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<charilepilots(a,c,0,n,dp)<<endl;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n+1;i++)
    {
        delete []dp[i];
    }
    delete []dp;
    
    return 0;
}

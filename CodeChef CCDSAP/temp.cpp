#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>arr){
    sort(arr.begin(),arr.end());
    int i=1;
	int dp[1002];
	
	map<int,int>m;
	map<int,int>::iterator it;
	
	for(int i=0;i<n;i++)
	m[arr[i]]++;
	
	it=m.begin();
	dp[0]=0;
	dp[1]= it->second;
	it++;
	i=2;
	while(it!=m.end())
	{
		dp[i]=max(dp[i-2]+(i * it->second),dp[i-1]);
	//	cout<<dp[i]<<" ";
        cout << "i: " << i << endl;
		it++;
		i++;
	}
	int ans=dp[i-1];
	delete[]dp;
	return ans;
}
int n;
vector<int>A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
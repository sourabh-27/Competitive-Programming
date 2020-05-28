#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

#define pb push_back
#define mp make_pair
#define ins insert

#define f(i,n) for(int i = 0 ;  i < n ; i++)
#define f1(i,n) for(int i = 1 ; i<= n ; i++)

#define int long long int

#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test() int t;cin>>t;while(t--)


set<int> adj[100001];


int32_t main()
{
	fast();

	int n , m ;
	cin >> n >> m ;

	int a[n+1];

	f1(i,n)
		cin >> a[i];

	for(int i = 0; i < m; i++)
	{
		int u , v;
		cin >> u >> v;

		adj[u].ins(a[v]);
		adj[v].ins(a[u]);

	}

	int good = 0 ;

	f1(i,n)
	{
		bool find = true;
		for(auto it = adj[i].begin() ; it!= adj[i].end() ; it++)
		{
			if(*it < a[i])
				break;
			else if(*it >= a[i])
			{
				find  = false;
				break;
			}	
		}

		if(find)
			good++;
	}


	cout<<good;


	return  0 ;
	
}



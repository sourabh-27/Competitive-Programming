#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int ,long long int >> mahakaal;
long long int x,y;
int masterball(vector<long long int>&popo,int n,int sum,int pos)
{
	if(pos>=n)
		return 0;
	int localsum=sum;
		localsum=sum;
		localsum+=popo[pos];
		mahakaal.push_back({localsum,(x&localsum)*(y&localsum)});
		masterball(popo,n,sum,pos+1);
		masterball(popo,n,localsum,pos+1);

		return 0;
}
bool compare(const pair<long long int,long long int >&a,const pair<long long int,long long int>&b)
{
	return (a.first<b.first and a.second>b.second) or (a.first>b.first and a.second>b.second) ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;long long int i,l,r,n,o;
	cin>>t;
	long long int a[46]={0};a[0]=1;
	for(i=1;i<=45;i++)
		a[i]=a[i-1]*2;
	while(t--)
	{
		cin>>x>>y>>l>>r;
		if(x==0 or y==0)
			cout<<0<<"\n";
		else if(r>=max(x,y) and l<=max(x,y))
		{
			long long int j=x|y;
			cout<<j<<"\n";
		}
		else
		{
		mahakaal.clear();
		int p=log2(x),m=log2(y);
		vector<int>v;
		vector<int>k;
		o=max(p,m)+1;
		n=x;
		while(n>0)
		{
			v.push_back(n%2);
			n=n/2;
		}
		n=y;
		while(n>0)
		{
			k.push_back(n%2);
			n=n/2;
		}
		v.resize(o);
		k.resize(o);
		long long int sum=0;
		int n=v.size();vector<long long int>popo;
		for(i=0;i<n;i++)
		{
			o=v[i]^k[i];
			if(o==0 and v[i]==1)
				sum+=a[i];
			else if(o==1)
				popo.push_back(a[i]);
		}
		
		if(r==sum)
			cout<<sum<<"\n";
		else
		{
			long long int localsum=0;
		
			mahakaal.push_back({sum,(x&sum)*(y&sum)});
			n=popo.size();
			masterball(popo,n,sum,0);
		

		
		sort(mahakaal.begin(),mahakaal.end(),compare);
		int valc=r,maxer=INT_MIN;
		for(i=0;i<mahakaal.size();i++)
		{
			if( mahakaal[i].first>=l and mahakaal[i].first<=r  and mahakaal[i].second>maxer)
			{
				valc=mahakaal[i].first;
				maxer=mahakaal[i].second;
				break;
			}
		}
		cout<<valc<<"\n";
		}
		}
		
	}
	return 0;
}

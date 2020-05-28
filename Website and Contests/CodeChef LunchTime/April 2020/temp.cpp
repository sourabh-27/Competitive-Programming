#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll check(set<ll> s)
{
	ll it=1;
     for(auto i=s.begin();i!=s.end();++i)
     {
          if(*i!=(it))
          return it;
          it=it+1;
     }
}
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	     ll n,i;
	     cin>>n;
	     ll a[n];
	     for(i=0;i<n;i++)
	     cin>>a[i];
	     unsigned ll opsize = pow(2, n); 
	     set<ll> v;ll s=0;
    for (ll counter = 1; counter < opsize; counter++) 
    { 
        for (ll j = 0; j < n; j++) 
        { 
            if (counter & (1<<j)) 
               v.insert(a[j]);
        } 
        s=s+check(v)%998244353;
        v.clear();
	}
	cout<<s+1<<endl;
	}
	return 0;
}
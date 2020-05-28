#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() 
{
    ll n,m;
    cin>>n>>m;
    priority_queue<ll> q; 
   
    for(ll i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
   
    ll temp=0;
    map<ll ,ll> map;
    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        map[x]++;
        temp=max(x,temp);
    }
    
    ll i=1;
    while(!q.empty() && i<=temp)
    {
        ll k=q.top();
        if(map[i]>0)
        {
            cout<<k<<endl;
        }
        q.pop();
        q.push(k/2);
        
        i++;
    }
}
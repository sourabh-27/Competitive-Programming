#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T int t;cin>>t;while(t--)
int main()
{
    T{
        ll n,k;
        cin>>n>>k;
        ll c[n+1],i,j,l=0,g,p;
        map<ll,ll>m;
        vector<ll>v;
        for(i=1;i<=n;i++)
        {
            cin>>c[i];
            m[c[i]]=i;
        }
        for(i=1;i<=n;i++)
        {
            if(m[i]!=i)
            {
                j=c[i];
                if(j!=i&&j!=m[i])
                {
                    l++;
                    ll i1=i,i2=j,i3=m[i],v1=c[i],v2=c[j],v3=i;
                    // cout << "i1: " << i1 << " i2: " << i2 << " i3: " << i3 << endl;
                    c[i]=i;
                    c[j]=v1;
                    c[i3]=v2;
                    m[i]=i;
                    m[v1]=i2;
                    m[v2]=i3;
                    v.push_back(i1);
                    v.push_back(i2);
                    v.push_back(i3);
                }
            }
        }
        for(i=1;i<=n;i++)
        if(m[i]!=i)
        {
            j=i;
            for(p=n;p>=i+1;p--)
            if(m[p]!=p&&p!=i&&p!=m[i])
            {
                j=p;
                break;
            }
            if(j==i||j==m[i])
            break;
            else
            {
                l++;
                ll i1=i,i2=j,i3=m[i],v1=c[i],v2=c[j],v3=i;
                cout << "i1: " << i1 << " i2: " << i2 << " i3: " << i3 << endl;
                c[i]=i;
                c[j]=v1;
                c[i3]=v2;
                m[i]=i;
                m[v1]=i2;
                m[v2]=i3;
                v.push_back(i1);
                v.push_back(i2);
                v.push_back(i3);
            }
        }
        j=0;
        for(i=1;i<=n;i++)
        if(c[i]==i)
        j++;
        if(j==n&&l<=k)
        {
            cout<<l<<"\n";
            i=0;
            for(auto it:v)
            {
                if(i==3)
                {
                    cout<<"\n";
                    i=0;
                }
                i++;
                cout<<it<<" ";
            }
        }
        else
        cout<<-1<<"\n";
    }
}
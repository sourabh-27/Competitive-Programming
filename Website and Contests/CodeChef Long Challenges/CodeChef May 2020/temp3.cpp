#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define P pair<int,int>
#define pb push_back
#define F first
#define S second

int32_t main(){

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    int t; cin>>t; while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        a[0]=0;
        map<int,int> m;
        for (int i = 1; i <= n; ++i)
        {
            cin>>a[i];
            m[a[i]]=i;
        }
        int flag=0;
        int count=0;
        vector<int> X,Y,Z;
        for(int i=1;i<=n;i++)
        {
            if(m[i]==i)
            continue;
            int x=i;
            int y=m[i];
            int z=m[y];
            if(x==z)
            {
                flag=-1;
                break;
            }
            count++;
            X.pb(x);
            Y.pb(y);
            Z.pb(z);
            a[z]=a[i];
            m[a[z]]=z;
            a[x]=x;
            a[y]=y;
            m[a[x]]=x;
            m[a[y]]=y;
        }

        if(flag==-1||count>k)
            cout<<"-1\n";
            cout<<count<<"\n";
            for(int i=0;i<X.size();i++)
            {
                cout<<X[i]<<" "<<Y[i]<<" "<<Z[i]<<"\n";
            }
            for(int i=1;i<=n;i++)
            {
            	cout<<a[i]<<" ";
            }
    }
    return 0;
}
 #include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld      long double
#define pii     pair<int ,int>
#define pld     pair<ld ,ld>
#define F       first
#define S       second
#define mod     1000000007
#define pb      push_back
#define mp      make_pair
#define all(x)  x.begin(),x.end()
#define mset(x) memset(x, 0, sizeof(x));
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
struct point{
	ll x,y,v;
}; 

bool compare(point a,point b)
{
	return (a.v < b.v);		
}

signed main() 
{   ios;
    ll t;
    cin>>t;
    while(t--){
    ll n;
	cin>>n;
	point obj[n];
	for(ll i=0;i<n;i++)
	 cin>>obj[i].x>>obj[i].y>>obj[i].v;
	sort(obj,obj+n,compare);
    ll b[n][n];
     for(ll i=0;i<n;i++)
     for(ll j=0;j<n;j++)
       b[i][j]=0;
	ll m=0,x=0;
	for(ll i=0;i<n-1;i++){
	    m=max(m,x);
	     x=0;
		 for(ll j=i+1;j<n;j++){
             if(i==j)continue;
		    
		if(obj[i].v==obj[j].v){
		if( obj[i].x==obj[j].x || obj[i].y==obj[j].y || obj[j].x==obj[i].y || obj[j].y==obj[i].x )
		       b[i][j]=1;
		
		else if((obj[i].x<obj[j].x && obj[i].y<obj[j].x) || (obj[j].x<obj[i].x && obj[j].y<obj[i].x))
		{
		}
		else{
			b[i][j]=1;
		}
	}
	else {
		
		break;
	}
	}
	}
    bool f=false;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(b[i][j]!=1)continue;
            else{
                for(ll k=0;k<n;k++){
                    if(b[j][k]==1){
                        if(b[i][k]==1)
                        {f=true;break;}
                    }
                    if(f) 
                    break;
                }
                if(f) 
                    break;

            }
        }
        if(f) 
          break;
    }
	 
     if(f)
      cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
}
	return 0; 
}

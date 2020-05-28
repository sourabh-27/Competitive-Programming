#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fori0(x) for(int i=0;i<x;i++)
#define forj0(x) for(int j=0;j<x;j++)
#define fork0(x) for(int k=0;k<x;k++)
#define fori1(x) for(int i=1;i<=x;i++)
#define forj1(x) for(int j=1;j<=x;j++)
#define fork1(x) for(int k=1;k<=x;k++)
#define foriv(v) for(int i=0;i<v.size();i++)
#define forjv(v) for(int j=0;j<v.size();j++)
#define forkv(v) for(int k=0;k<v.size();k++)
#define testcase(t) for(int te=1;te<=t;te++)
#define nl "\n"
#define newl cout<<"\n"
#define print1(x) cout<<x<<"\n"
#define print2(x,y) cout<<x<<" "<<y<<"\n"
#define sorti(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(),v.end(), greater<int>())
#define ff first
#define ss second
#define test printf("test")
#define printv(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<"\n"
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;
typedef vector< pair<ll,ll> > vpl;
typedef map<int,int> mapi;
typedef map<ll,ll> mapll;
#define intScan(t) scanf("%d",&t)
#define llScan(t) scanf("%lld",&t)
// typedef unordered_map<int,int> umapi;
// typedef unordered_map<ll,ll> umapll;

int power(int n,int r){
    int ans = 1;
    fori0(r){
        ans*=n;
    }
    return ans;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////   CODE -----   //////////

int* convert(ll n){
    int *arr = new int [63];

    fori0(63){
        arr[i]=0;
    }

    for(int i=0;;i++){
        arr[i] = n%2;
        n = n/2;

        if(n==1 || n==0){
            arr[i+1] = n;
            break;
        }
    }

    int *str = new int[63];

    fori0(63){
        str[i] = arr[62-i];
    }
    
    return str;
}

ll convertINT(int *arr){
    ll ans=0;

    ll counter = 1;
    for(int i=62;i>=0;i--){
        ans+=arr[i]*counter;
        counter*=2;
    }
    return ans;
}

ll compute(ll x, ll y, ll z){
    ll a1 = x&z;
    ll a2 = y&z;
    ll ans = a1*a2;
    return ans;
}

bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.ff > b.ff); 
}


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    int t;
    intScan(t);

    while(t--){
        ll x,y;
        llScan(x);llScan(y);
        ll l,r;
        llScan(l);llScan(r);

        ll xORy = x|y;

        int *arrX = convert(x);
        int *arrY = convert(y);
        int *arrXY = convert(xORy);
        int *arrR = convert(r);

        int *baseArray = new int [63];
        vpl v1;

        fori0(63){
            baseArray[i]=(arrXY[i] & arrR[i]);
            // cout << "i: " << i << " baseArray[i]: " << baseArray[i] << endl;
        }
        ll a1 = convertINT(baseArray);
        // cout << "a1: " << a1 << endl;
        pl pair1;
        pair1.ff = compute(x,y,a1);
        pair1.ss = a1;
        v1.pb(pair1);

        fori0(63){
            if(arrR[i]==1){

                int *dummy = new int [63];
                for(int j=0;j<i;j++){
                    dummy[j]=baseArray[j];
                }
                dummy[i]=0;
                for(int j=i+1;j<63;j++){
                    dummy[j]=arrXY[j];
                }

                ll intValue = convertINT(dummy);
                pl pairDummy;
                pairDummy.ff = compute(x,y,intValue);
                pairDummy.ss = intValue;
                v1.pb(pairDummy);


            }
        }

        sort(v1.begin(),v1.end(),sortbysec);
        for(ll i = 0; i < v1.size(); i++){
            // cout << "first: " << v1[i].first << " second: " << v1[i].second << endl;
        }
        ll maximum=v1[0].ff;
        ll value=v1[0].ss;

        // foriv(v1){
        //     cout<<v1[i].ss<<" "<<v1[i].ff<<nl;
        // }

        foriv(v1){
            if(v1[i].ff == maximum){
                if(value > v1[i].ss){
                    value = v1[i].ss;
                }
            }else{
                break;
            }
        }

        if(maximum==0){
            cout<<0<<nl;
        }else{
            cout<<value<<nl;
        }
        

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define INF 0x3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define print(v); for(auto x:v) cout<<x<<" "; cout<<endl;
typedef long long int ll;
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        unordered_map<ll, ll> umap;
        set<ll> se;
        for(ll i = 0; i < n; i++){
            ll k; cin >> k;
            se.insert(k);
            umap[k]++;
        }
        ll flag = 0;
        ll sum1 = 0; ll sum2 = 0;
        for(auto x: se){
            if(flag == 0){
                sum1 += x * umap[x];
                flag = 1;
            }
            else{
                flag = 0;
                sum2 += x * umap[x];
            }
        }
        cout << se.size() << " " << sum1 << " " << sum2 << endl;


    }


    return 0;
}
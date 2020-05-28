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

ll nCr(ll n, ll r) 
{
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            long long m = __gcd(p, k); 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
    else
        p = 1; 
    return p;
}
int main()
{
    fast;
    ll n;
    cin >> n;
    long long arr[n + 1]; 
    unordered_map<ll, ll> umap;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        umap[arr[i]]++;
    }
    ll count = 0;
    for(auto x: umap){
        if(x.second > 1){
            count = count + nCr(x.second, 2);
        }
    }
    // cout << count << endl;
    ll ans;
    for(ll i = 0; i < n; i++){
        umap[arr[i]]--;
        ans = count - umap[arr[i]];
        umap[arr[i]]++;
        cout << ans << endl;
    }
    cout << endl;



    return 0;
}
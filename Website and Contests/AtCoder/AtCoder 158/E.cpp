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

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % mod;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % mod;
        return cur;
    }
}

int main()
{
    fast;
    ll n, p;
    cin >> n >> p;
    string str;
    cin >> str;
    unordered_map<ll, ll> umap;
    ll power = 0; 
    for(ll i = n - 1; i >= 0; i--){
        int ch = str[i] - 48;
        power = (modExp(10, n - i - 1) % mod + ch % mod) % mod;
        cout << "power: " << power << endl;
        umap[power]++;
    }


    return 0;
}
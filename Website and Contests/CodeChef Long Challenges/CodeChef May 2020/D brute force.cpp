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

ll bruteForce(ll x, ll y, ll l, ll r){
    ll maxi = INT_MIN; ll z;
    for(ll i = l; i <= r; i++){
        ll k = (x & i) * (y & i);
        if(k > maxi){
            maxi = k;
            z = i;
        }
    }
    return z;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll x, y, l, r;
        cin >> x >> y >> l >> r;
        cout << bruteForce << endl;
    }


    return 0;
}
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
        ll x, y;
        cin >> x >> y;
        ll a, b;
        cin >> a >> b;
        ll maxi = max(y, x);
        ll mini = min(y, x);
        ll ans = min(min((mini * b) + (maxi - mini) * a, (maxi + mini) * a), (maxi - mini) * a + maxi * b);
        cout << ans << endl;
    }
 
 
    return 0;
}
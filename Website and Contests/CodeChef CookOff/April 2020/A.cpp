#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;
        ll initial = 0; ll ans = 0;
        while(q--){
            ll x, y;
            cin >> x >> y;
            ans += abs(initial - x) + abs(x - y);
            initial = y;
            // cout << "initial: " << 
        }
        cout << ans << endl;
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

struct point{
    ll xC;
    ll yC;
};
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;

        struct point arr[n + 1];
        for(ll i = 1; i <= n; i++){
            ll k;
            cin >> k;
            arr[i].xC = i; 
            arr[i].yC = k;
        }
        for(ll i = 1; i <= n; i++){
            cout << arr[i].xC << " " << arr[i].yC << endl;
        }

        while(q--){
            ll x1, x2, y;
            cin >> x1 >> x2 >> y;
            vector<pair<ll, ll>> points;
            for(ll i = 1; i < n; i++){
                ll m = (arr[i + 1].yC - arr[i].yC) / (arr[i + 1].xC - arr[i].xC);
                ll ans = ((y - arr[i].yC) / m) + arr[i].xC;
                points.push_back({ans, y});
            }
            for(ll i = 0; i < points.size(); i++){
                cout << "x: " << points[i].first << " y: " << points[i].second << endl;
            }
        }
        
    }

    return 0;
}
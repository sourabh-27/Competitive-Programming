#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n; cin >> n;
    long long a[n + 1], b[n + 1], c[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    for(ll i = 0; i < n; i++){
        c[i] = a[i] - b[i];
    }
    sort(c, c + n);
    for(ll i = 0; i < n; i++){
        cout << c[i] << " ";
    }
    cout << endl;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(c[i] <= 0){
            continue;
        }
        auto x = lower_bound(c, c + n, -c[i] + 1);
        cout << "i: " << i << " x: " << x - c << endl;
        ans += i - (x - c);
    }
    cout << ans << endl;


    return 0;
}
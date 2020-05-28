#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a % b == 0){
            cout << 0 << endl;
        }
        else{
            ll ans = (a / b + 1) * b;
            cout << ans - a << endl;
        }
    }


    return 0;
}
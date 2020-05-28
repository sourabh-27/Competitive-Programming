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
        ll n;
        cin >> n;
        ll ans;
        if(n % 2 == 0){
            ans = n / 2 - 1;
        }
        else{
            ans = n / 2;
        }
        if(ans <= 2 && n <= 2){
            cout << 0 << endl;
        }
        else{
            cout << ans << endl;
        }
    }

    return 0;
}
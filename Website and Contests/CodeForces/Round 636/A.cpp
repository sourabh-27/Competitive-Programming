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
        ll x;
        cin >> x;
        for(ll i = 2; i <= x; i++){
            ll power = pow(2, i);
            if(x % (power - 1) == 0){
                cout << x / (power - 1) << endl;
                break;
            }
        }
    }


    return 0;
}
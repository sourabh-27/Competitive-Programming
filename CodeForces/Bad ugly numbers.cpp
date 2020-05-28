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
        if(n == 1){
            cout << -1 << endl;
        }
        else{
            for(ll i = 0; i < n - 1; i++){
                cout << 7;
            }
            cout << 3 << endl;
        }
    }

    return 0;
}
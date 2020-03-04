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
        ll n, m;
        cin >> n >> m;
        ll sum = (n * (n + 1)) / 2;
        m = m % sum;
        for(ll i = 1; i <= n; i++){
            ll check = m - i;
            if(check < 0){
                break;
            }
            m = check;
        }
        cout << m << endl;
    }

    return 0;
}
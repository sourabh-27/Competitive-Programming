#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

ll bruteForce(long long * arr, ll n){
    ll count = 0;
        for(ll i = 0; i < n; i++){
            ll mul = 1;
            // cout << "YO" << endl;
            for(ll j = i; j < n; j++){
                mul = mul * arr[j];
                // cout << "i: " << i << " j: " << j << endl;
                // cout << "mul:" << mul << endl;
                if(mul % 2 != 0 || mul % 4 == 0){
                    // cout << "mul:" << mul << endl;
                    count++;
                    if(mul >= 100){
                        mul = (((mul / 10) % 10) * 10) + (mul % 10);
                        // cout << "new mul: " << mul << endl;
                    }
                }
                // else{
                //     break;
                // }
            }
        }
    return count
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        long long arr[n + 1];
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        
    }

    return 0;
}
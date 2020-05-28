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
        ll n;
        cin >> n;
        if((n / 2) % 2 != 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            ll even = 2, odd = 1; ll sum = 0, sum2 = 0;
            for(ll i = 1; i <= (n / 2); i++){
                cout << even << " ";
                sum += even;
                even +=2;
            }
            for(ll i = 1; i < (n / 2); i++){
                cout << odd << " ";
                sum2 += odd;
                odd += 2;
            }
            cout << sum - sum2;
            cout << endl;
        }
    }


    return 0;
}
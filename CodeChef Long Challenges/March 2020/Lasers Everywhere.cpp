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
        ll n, q;
        cin >> n >> q;
        long long arr[n + 1];
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
            cout << arr[i] << " ";
        }
        cout  << endl;

        while(q--){
            ll x1, x2, y;
            cin >> x1 >> x2 >> y;
            ll count = 0;
            for(ll i = x1 + 1; i <= x2; i++){
                // cout << "arr[i]: " << arr[i] << " arr[i - 1]: " << arr[i - 1] << endl;
                if(y <= arr[i] && y >= arr[i - 1]){
                    // cout << "arr[i]: " << arr[i] << " arr[i - 1]: " << arr[i - 1] << endl;
                    count++;
                }
                else if(y >= arr[i] && y <= arr[i - 1]){
                    // cout << "arr[i]: " << arr[i] << " arr[i - 1]: " << arr[i - 1] << endl;
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}
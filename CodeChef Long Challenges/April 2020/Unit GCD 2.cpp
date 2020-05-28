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
        if(n <= 3){
            cout << 1 << endl;
            cout << n << " ";
            for(ll i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            ll count = 1;
            ll temp = n - 3;
            if(temp % 2 == 0){
                count = count + temp / 2;
            }
            else{
                count = count + temp / 2 + 1;
            }
            cout << count << endl;
            cout << 3 << " ";
            for(ll i = 1; i <= 3; i++){
                cout << i << " ";
            }
            cout << endl;
            if(n % 2 == 0){
                for(ll i = 4; i < n; i += 2){
                    cout << 2 << " " << i << " " << i + 1 << endl;
                }
                cout << 1 << " " << n << endl;
            }
            else{
                for(ll i = 4; i <= n; i += 2){
                    cout << 2 << " " << i << " " << i + 1 << endl;
                }
            }
        }
    }

    return 0;
}
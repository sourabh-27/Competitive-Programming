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
        ll n, a, b;
        cin >> n >> a >> b;
        char ch = 'a';
        string ans = "";
        ll count = 0;
        for(ll i = 0; i < b; i++){
            ans = ans + ch;
            ch = ch + 1;
            count++;
            if(count == b){
                count = 0;
                ch = 'a';
            }
        }
        ll k = 0;
        for(ll i = 0; i < n; i++){
            cout << ans[k];
            k++;
            if(k == b){
                k = 0;
            }
        }
        cout << endl;

    }

    return 0;
}
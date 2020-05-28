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
        string str;
        cin >> str;
        ll left = -1; ll right = -1;
        for(ll i = 0 ; i < str.length(); i++){
            if(str[i] == 'R'){
                left = i;
                break;
            }
        }
        for(ll i = str.length() - 1; i >= 0; i--){
            if(str[i] == 'R'){
                right = i;
                break;
            }
        }
        ll maxi = INT_MIN; ll index = -1;
        for(ll i = 0; i < str.length(); i++){
            if(str[i] == 'R' && index == -1){
                index = i;
            }
            else if(str[i] == 'R'){
                maxi = max(maxi, i - index);
                index = i;
            }
        }
        ll ans1 = left + 1; ll ans2 = str.length() - right;
        cout << max(ans1, max(ans2, maxi)) << endl;
    }


    return 0;
}
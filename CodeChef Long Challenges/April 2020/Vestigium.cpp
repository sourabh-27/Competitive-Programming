#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll t;
    cin >> t;
    for(ll x = 1; x <= t; x++){
        ll n;
        cin >> n;
        long long arr[n + 1][n + 1];
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                cin >> arr[i][j];
                if(i == j){
                    sum += arr[i][j];
                }
            }
        }
        ll rC =  0, cC = 0;
        for(ll i = 0; i < n; i++){
            unordered_map<ll, ll> mp1;
            for(ll j = 0; j < n; j++){
                mp1[arr[i][j]]++;
                if(mp1[arr[i][j]] >= 2){
                    rC++;
                    break;
                }
            }
        }
        for(ll i = 0; i < n; i++){
            unordered_map<ll, ll> mp1;
            for(ll j = 0; j < n; j++){
                mp1[arr[j][i]]++;
                if(mp1[arr[j][i]] >= 2){
                    cC++;
                    break;
                }
            }
        }
        rC = (rC == 1) ? 0 : rC;
        cC = (cC == 1) ? 0 : cC;
        cout << "Case #" << x << ": " << sum << " " << rC << " " << cC << endl;
    }
}
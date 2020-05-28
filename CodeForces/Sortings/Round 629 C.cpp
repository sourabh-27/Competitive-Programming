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
        string str;
        cin >> str;
        string a = "", b = "";
        unordered_map<ll, bool> umap;
        for(ll i = 0; i < n; i++){
            if(str[i] == '0'){
                char k = '0';
                umap[i] = true;
                a += k;
                continue;
            }
            a += str[i] - 1;
        }
        cout << a << endl;
        for(ll i = 0; i < n; i++){
            if(umap[i]){
                b += '0';
                // continue;
            }
            else{
                b += '1';
            }
        }
        cout << b << endl;
    }


    return 0;
}
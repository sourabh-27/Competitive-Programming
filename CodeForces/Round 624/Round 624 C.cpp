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
        ll n, m;
        cin >> n >> m;
        string str;
        cin >> str;
        unordered_map<ll, bool> umap;
        for(ll i = 0; i < m; i++){
            ll x; cin >> x;
            x--;
            umap[x] = true;
        }

        long long arr[256] = {0};
        ll count = 1;
        for(ll i = str.length() - 1; i >= 0; i--){
            if(umap[i] == true){
                count++;
            }
            arr[str[i] - 'a'] += count;
            // cout << "i: " << i << " count: " << arr[str[i] - 'a'] << endl;
        }
        char k = str[0];
        str = str.substr(1);
        // cout << "find:" << str.find(k) << endl;
        if(umap[0] == true && str.find(k) == -1){
            // cout << "YO" << endl << " value: "<< str.find(k) << endl;
            arr[k - 'a']--;
        }
        for(ll i = 0; i < 26; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    return 0;
}
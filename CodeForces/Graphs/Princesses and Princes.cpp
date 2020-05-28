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
        vector<vector<ll>> graph(n + 1);
        for(ll i = 1; i <= n; i++){
            ll m; cin >> m;
            for(ll j = 0; j < m; j++){
                ll k; cin >> k;
                graph[i].push_back(k);
            }
        }
        bool visited[n + 1], princess[n + 1];
        memset(visited, false, sizeof(visited));
        memset(princess, false, sizeof(princess));
        // cout << "n: " << n << endl;
        for(ll i = 1; i <= n; i++){
            // cout << "i: " << i << " graph[i]: " << graph[i].size() << endl;
            for(ll j = 0; j < graph[i].size(); j++){
                // cout << "i: " << i  <<  " j : " << graph[i][j] << endl;
                if(visited[graph[i][j]]){
                    // cout << "YO "  << j + 1 << endl;
                    continue;
                }
                else{
                    princess[i] = true;
                    visited[graph[i][j]] = true;
                    // cout << "i: " << i << " married to: " << graph[i][j] << endl;
                    break;
                }
            }
        }
        ll ans = 0; ll index = 0;
        for(ll i = 1; i <= n; i++){
            if(!visited[i]){
                ans = i;
                break;
            }
        }
        for(ll i = 1; i <= n; i++){
            if(!princess[i]){
                index = i;
            }
        }
        if(ans == 0 || index == 0){
            cout << "OPTIMAL" << endl;
        }
        else{
            cout << "IMPROVE" << endl;
            cout << index << " " << ans << endl;
        }
    }


    return 0;
}
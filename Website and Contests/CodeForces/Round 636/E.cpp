#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;

vector<vector<ll>> vec(5 * 1e5 + 20);

void bfs(ll a, long long * arr){
    queue<ll> que;
    que.push(a);
    arr[a] = 0;
    while(!que.empty()){
        ll k = que.front();
        que.pop();
        for(ll i = 0; i < vec[k].size(); i++){
            if(arr[vec[k][i]] == INT_MAX){
                arr[vec[k][i]] = arr[k] + 1;
                // cout << "vec[k][i]: " << vec[k][i] << " arr[k]: " << arr[k] + 1 << endl;
                que.push(vec[k][i]);
            }
        }
    }
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        long long price[m + 1];
        for(ll i = 0; i < m; i++){
            cin >> price[i];
        }
        // cout << "YO" << endl;
        sort(price, price + m);
        long long prefix[m + 2];
        prefix[0] = 0;
        prefix[1] = price[0];
        for(ll i = 2; i <= m; i++){
            prefix[i] = prefix[i - 1] + price[i - 1];
            // cout << "i: " << i << " prefix: " << prefix[i] << endl;
        }
        // cout << "YO2" << endl;
        for(ll i = 0; i < m; i++){
            ll x, y;
            cin >> x >> y;
            vec[x].pb(y);
            vec[y].pb(x);
        }
        // cout << "YO3" << endl;
        long long distA[n + 2], distB[n + 2], distC[n + 2];
        for(ll i = 0; i <= n + 1; i++){
            distA[i] = distB[i] = distC[i] = INT_MAX;
        }
        // cout << "YO4" << endl;
        bfs(a, distA); bfs(b, distB); bfs(c, distC);
        ll final = 1e18;
        for(ll i = 1; i <= n; i++){
            if(distA[i] + distB[i] + distC[i] > m){
                continue;
            }
            else{
                // cout << "distB[i]: " << distB[i] << " distA[i]: " << distA[i] << " distC[i]: " << distC[i] << endl;
                ll ans = prefix[distB[i]];
                ll ans2 = prefix[distA[i] + distB[i]] - ans;
                ll ans3 = prefix[distA[i] + distB[i] + distC[i]] - ans2 - ans;
                // cout << "ans: " << ans << " ans2: " << ans2 << " ans3 1: " << ans3 << " sum: " << ans * 2 + ans2 + ans3 << endl;
                final = min(final, ans * 2 + ans2 + ans3);
            }
        }
        cout << final << endl;
        for(ll i = 1; i <= n; i++){
            vec[i].clear();
        }
    }


    return 0;
}
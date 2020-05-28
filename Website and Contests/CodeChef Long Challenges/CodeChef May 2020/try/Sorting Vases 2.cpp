#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define INF 0x3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define print(v); for(auto x:v) cout<<x<<" "; cout<<endl;
typedef long long int ll;
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        long long arr[n + 2]; long long num[n + 2];
        ll count = 0;
        unordered_map<ll, ll> umap2;
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
            num[i] = i;
            umap2[i] = i;
        }
        // cout << "count: " << count << endl;
        long long posi[20][20];
        for(ll i = 0; i <= 19; i++){
            for(ll j = 0; j <= 19; j++){
                posi[i][j] = 0;
            }
        }
        for(ll i = 1; i <= m; i++){
            ll x, y;
            cin >> x >> y;
            posi[x][y] = 1; posi[y][x] = 1;
        }

        unordered_map<ll, ll> final, final2;
        for(ll i = 1; i <= n; i++){
            if(umap2[i] == arr[i]){
                continue;
            }
            else{
                count++;
                ll e1 = umap2[i]; ll e2 = arr[i];
                // cout << "e1: " << e1 << " e2: " << e2 << endl;
                final[e1]++; final2[e2]++;
                ll val1 = num[e1]; ll val2 = num[e2];
                num[e1] = val2; num[e2] = val1;
                umap2[val1] = e2; umap2[val2] = e1;
            }
        }
        ll count2 = 0;
        for(auto &x: final){
            // cout << "x.first: " << x.first << endl;
            ll first = x.second;
            ll second;
            for(ll i = 1; i <= 19; i++){
                if(posi[x.first][i] == 1 || posi[i][x.first] == 1){
                    second = final[i];
                    // cout << "first: " << first << " second: " << second << endl;
                    ll mini = min(first, second);
                    if(mini < 0){
                        mini = 0;
                    }
                    count2 = count2 + mini;
                    final[x.first] -= mini; final[i] -= mini;
                }
            }
            
        }
        ll count3 = 0;
        for(auto &x: final2){
            // cout << "x.first: " << x.first << endl;
            ll first = x.second;
            ll second;
            for(ll i = 1; i <= 19; i++){
                if(posi[x.first][i] == 1 || posi[i][x.first] == 1){
                    second = final2[i];
                    // cout << "first: " << first << " second: " << second << endl;
                    ll mini = min(first, second);
                    if(mini < 0){
                        mini = 0;
                    }
                    count3 = count3 + mini;
                    final2[x.first] -= mini; final2[i] -= mini;
                }
            }
            
        }

        // cout << "count2: " << count2 << endl;
        // cout << "count3: " << count3 << endl;
        cout << count - count2 - count3 << endl;
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define INF 0x3f3f3f3f 
typedef long long int ll;
 
vector<vector<pair<ll, ll>>> graph(5 * 1e5 + 20);
vector<ll> dist(5 * 1e5 + 20);
vector<ll> parent(5 * 1e5 + 10);

void dijkastra(ll n, ll src){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[src] = 0;
    parent[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        ll k = pq.top().second;
        pq.pop();
        for(auto x: graph[k]){
            ll v = x.first;
            ll weight = x.second;
            if(dist[v] > dist[k] + weight){
                dist[v] = dist[k] + weight;
                pq.push({dist[v], v});
                parent[v] = k;
            }
        }
    }
    // for(ll i = 0; i <= n; i++){
    //     cout << "i: " << i << " dist[i]: " << dist[i] << " and parent[i]: " << parent[i] << endl;
    // }
}

int main()
{
    fast;
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].pb({b, c});
        graph[b].pb({a, c});
    }

    // cout << "YO1" << endl;
    for(ll i = 0; i <= 100010; i++){
        dist[i] = 1e18;
        parent[i] = -1;
    }
    // cout << "Yo2" << endl;
    dijkastra(n, 1);
    // cout << "YO3" << endl;
    ll x = n;
    vector<ll> vec;
    // cout << "x: " << x << endl;
    while(x != 1){
        // cout << "I am at x: " << x << endl;
        if(x == -1 || x == 1e18){
            break;
        }
        vec.push_back(x);
        x = parent[x];
    }
    if(x == -1 || x == 1e18){
        cout << -1 << endl;
        return 0;
    }
    vec.pb(1);
    reverse(all(vec));
    rep(i, 0, vec.size()) cout << vec[i] << " ";
    cout << endl;

    return 0;
}
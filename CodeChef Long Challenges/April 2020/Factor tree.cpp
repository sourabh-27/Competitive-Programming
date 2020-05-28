#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

#define MAXN 1000001 
  
long long spf[MAXN]; 
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        {
            for (ll j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

void dfsUtil(vector<ll> graph[], ll sV, ll dest, unordered_map<ll, ll> &umap, long long * arr, bool * visited, int &flag){
    if(sV == dest){
        flag = 1;
        return;
    }
    visited[sV] = true;
    for(ll i = 0; i < graph[sV].size(); i++){
        if(!visited[graph[sV][i]]){
            umap[arr[graph[sV][i]]]++;
            dfsUtil(graph, graph[sV][i], dest, umap, arr, visited, flag);
            if(flag == 1){
                return;
            }
            umap[arr[graph[sV][i]]]--;
        }
    }
}

void fillUmap2(unordered_map<ll, ll> &umap2, ll key, ll times){
    while(key != 1){
        umap2[spf[key]] += times;
        key = key / spf[key];
    }
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    sieve();
    while(t--){
        ll n;
        cin >> n;
        vector<ll> graph[n + 2];
        for(ll i = 0; i < n - 1; i++){
            ll x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        long long * arr = new long long [n + 1];
        for(ll i = 1; i <= n; i++){
            cin >> arr[i];
        }
        // cout << "YO" << endl;
        ll q;
        cin >> q;
        while(q--){
            ll x, y;
            cin >> x >> y;
            unordered_map<ll, ll> umap;
            bool * visited = new bool[n + 1];
            int flag = 0;
            memset(visited, false, sizeof(visited));
            umap[arr[x]]++;
            dfsUtil(graph, x, y, umap, arr, visited, flag);
            delete[] visited;
            unordered_map<ll, ll> umap2;
            for(auto x: umap){
                // cout << "first: " << x.first << " second: " << x.second << endl;
                fillUmap2(umap2, x.first, x.second);
            }
            ll ans2 = 1;
            for(auto y: umap2){
                // cout << "first: " << y.first << " second: " << y.second << endl;
                ans2 = (y.second + 1) * ans2;
                // if(ans2 >= mod){
                //     ans2 -= mod;
                // }
            }
            cout << ans2 % mod << endl;

        }
    }

    return 0;
}
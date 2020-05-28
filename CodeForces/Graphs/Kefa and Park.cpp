#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
vector<vector<ll>> graph(5*1e5 + 20);
long long arr[(int)(5*1e5 + 10)];
ll n, m, final = 0;

void dfs(ll sV, ll parent, ll count){
    // cout << "I am at : " << sV << " and count: " << count << endl;
    if(count > m) return;
    ll flag = 1;
    for(ll i = 0; i < graph[sV].size(); i++){
        if(graph[sV][i] != parent){
            flag = 0;
            dfs(graph[sV][i], sV, count*arr[graph[sV][i]] + arr[graph[sV][i]]);
        }
    }
    final += flag;
}

int main()
{
    fast;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(ll i = 0; i < n - 1; i++){
        ll x, y;
        cin >> x >> y;
        graph[x].pb(y); graph[y].pb(x);
    }
    dfs(1, -1, arr[1]);
    cout << final << endl;

    return 0;
}
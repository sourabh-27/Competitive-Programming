#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;
 
vector<vector<ll>> graph(5*1e5 + 20);
ll n;
void bfs(long long * parent){
    queue<ll> que;
    parent[1] = 0;
    que.push(1);
    while(!que.empty()){
        ll front = que.front();
        cout << "I am at: " << front << endl;
        que.pop();
        for(ll i = 0; i < graph[front].size(); i++){
            if(parent[graph[front][i]] == -1){
                parent[graph[front][i]] = front;
                que.push(graph[front][i]);
            }
        }
    }
    return;
}

int main()
{
    fast;
    ll m;
    cin >> n >> m;
    long long arr[n + 1];
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(ll i = 0; i < n - 1; i++){
        ll x, y;
        cin >> x >> y;
        graph[x].pb(y); graph[y].pb(x);
    }
    long long parent[n + 5];
    memset(parent, -1, sizeof(parent));
    bfs(parent);
    for(ll i = 1; i <= n; i++){
        cout << parent[i] << " ";
    }
    cout << endl;


    return 0;
}
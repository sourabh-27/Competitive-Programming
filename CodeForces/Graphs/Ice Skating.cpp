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
typedef long long int ll;

long long x[101], y[101];
ll n;

void dfs(ll sV, bool * visited){
    visited[sV] = true;
    for(ll i = 1; i <= n; i++){
        if(!visited[i] && (x[sV] == x[i] || y[sV] == y[i])){
            dfs(i, visited);
        }
    }
    return;
}

int main()
{
    fast;
    cin >> n;
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(x));
    for(ll i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    ll count = 0;
    for(ll i = 1; i <= n; i++){
        if(!visited[i]){
            // cout << "i: " << i << endl;
            dfs(i, visited);
            count++;
        }
    }

    cout << count - 1 << endl;

    return 0;
}
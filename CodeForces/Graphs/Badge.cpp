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
 
int main()
{
    fast;
    ll n;
    cin >> n;
    long long parent[n + 1];
    for(ll i = 1; i <= n; i++){
        cin >> parent[i];
    }
    for(ll i = 1; i <= n; i++){
        ll x = i;
        unordered_map<ll, bool> umap;
        while(umap[x] == false){
            umap[x] = true;
            x = parent[x];
        }
        cout << x << " ";
    }
    cout << endl;


    return 0;
}
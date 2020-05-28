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
    ll n;
    cin >> n;
    long long parent[2002];
    for(ll i = 1; i <= n; i++){
        cin >> parent[i];
    }

    ll depth = 0;
    for(ll i = 1; i <= n; i++){
        ll ans = 1;
        ll x = i;
        while(parent[x] != -1){
            ans++;
            x = parent[x];
        }
        depth = max(depth, ans);
    }
    cout <<  depth << endl;


    return 0;
}
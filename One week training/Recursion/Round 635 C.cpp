#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

#define maxi 200005
vector<ll> vec[maxi];
long long distFromParent[maxi + 1] = {0}, sizeArr[maxi + 1] = {0};
vector<ll> ans;

ll dfs(ll current, ll parent){
    distFromParent[current] = distFromParent[parent] + 1;
    sizeArr[current] = 1;
    for(ll i = 0; i < vec[current].size(); i++){
        if(vec[current][i] != parent){
            sizeArr[current] += dfs(vec[current][i], current);
        }
    }
    // cout << "I am at: " << current << " and calculating: " << sizeArr[current] - distFromParent[current] << endl;
    ans.push_back(sizeArr[current] - distFromParent[current]);
    return sizeArr[current];
}
 
int main()
{
    fast;
    ll n, k;
    cin >> n >> k;
    for(ll i = 0; i < n - 1; i++){
        ll x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    dfs(1, 0);
    sort(ans.begin(), ans.end());
    ll sum = 0;
    for(ll i = ans.size() - 1; i >= k; i--){
        sum += ans[i];
    }
    cout << sum << endl;

    return 0;
}
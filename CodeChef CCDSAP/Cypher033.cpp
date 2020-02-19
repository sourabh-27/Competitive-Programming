#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll arr[n + 1];
    set<ll> s;
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    set<ll>:: iterator itr;
    


    return 0;
}
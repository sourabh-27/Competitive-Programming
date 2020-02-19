#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n;
    cin >> n;
    vector<ll> vec;
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vec.push_back(x);
    }
    
    ll m;
    cin >> m;

    for(ll i = 0; i < vec.size(); i++)
    {
        if(vec[i] == m)
        {
            cout << i<< endl;
            break;
        }
    }

    return 0;
}
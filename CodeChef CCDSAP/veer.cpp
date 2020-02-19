#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
long long memorize[10000000];
ll findAns(vector<ll> vec, ll maxi, ll n, ll k)
{

    if(memorize[maxi] != -1)
    {
        return memorize[maxi];
    }

    if(maxi >= n)
    {
        if(maxi != n)
        {
            return 0;
        }
        else 
        {
            return 1;
        }
    }
    ll currIndex = 0;
    for(ll i = 0; i < k; i++)
    {
        currIndex = currIndex + findAns(vec, maxi + vec[i], n, k);
    }
    memorize[maxi] = currIndex % mod;
    return currIndex;
}
int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        
        vector<ll> vec;
        for(int i = 0; i < k; i++)
        {
            ll x;
            cin >> x;
            vec.push_back(x);
        }
        memset(memorize, -1, sizeof(memorize));
        ll start = 0;
        ll ans = findAns(vec, start, n, k);
        cout << ans % mod << endl;
    }
    return 0;
}
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
    ll start = 1;
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= i; j++)
        {
            cout << start << "        ";
            start = start + 1;
        }
        cout << endl;
    }

    return 0;
}
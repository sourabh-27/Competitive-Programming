#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    ll n1, n2;
    cin >> n1 >> n2;
    ll i = 0; ll j = 1;
    while(i != n1)
    {
        ll k = 3 * j + 2;
        if(k % n2 != 0)
        {
            cout << k << endl;
            i++;
        }
        j++;
    }

    return 0;
}
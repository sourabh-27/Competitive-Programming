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
    for(ll i = 1; i <= (n / 2) + 1; i++)
    {
        ll totalSpaces = (n - ((2 * i) - 1)) / 2;
        for(ll j = 1; j <= totalSpaces; j++)
        {
            cout << "        ";
        }

        for(ll j = 1; j <= (2 * i) - 1; j++)
        {
            cout << "*" << "       ";
        }

        for(ll j = 1; j < totalSpaces; j++)
        {
            cout << "        ";
        }
        cout << endl;
    }

    for(ll i = (n / 2); i >= 1; i--)
    {
        ll totalSpaces = (n - ((2 * i) - 1)) / 2;
        for(ll j = 1; j <= totalSpaces; j++)
        {
            cout << "        ";
        }

        for(ll j = 1; j <= (2 * i) - 1; j++)
        {
            cout << "*" << "       ";
        }

        for(ll j = 1; j < totalSpaces; j++)
        {
            cout << "        ";
        }
        cout << endl;
    }

    return 0;
}
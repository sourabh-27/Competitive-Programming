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
    ll first = 0; ll second = 1;
    cout << first << endl;
    for(ll i = 2; i <= n; i++)
    {
        cout << second << "        ";
        ll temp = second;
        second = first + second;
        first = temp;
        for(ll j = 2; j < i; j++)
        {
            cout << second << "        ";
            ll temp2 = second;
            second = first + second;
            first = temp2;
        }
        cout << second << endl;
        ll tempa = second;
        second = first + second;
        first = tempa;

    }

    return 0;
}
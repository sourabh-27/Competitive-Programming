#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    string k1, k2;
    for(ll i = 0; i < a; i++)
    {
        k1 += b + 48;
    }
    for(ll i = 0; i < b; i++)
    {
        k2 += a + 48;
    }   
    if(k1 == k2)
    {
        cout << k1 << endl;
    }
    else if(k1 > k2)
    {
        cout << k2 << endl;
    }
    else
    {
        cout << k1 << endl;
    }

    return 0;
}
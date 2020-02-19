#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

ll lastSet(ll n) 
{ 
    ll k = n & (n - 1); 
    return (n ^ k); 
} 

ll glr(ll x)
{
    if(x == 0)
    {
        return 0;
    }
    ll sum = (x * (x + 1)) / 2;
    ll initial = x;
    ll power = 0;
    ll sumA = 0;
    while(x >= 1)
    {
        ll count = (x + 1) / 2;
        sumA += count * pow(2, power);
        x = x - count;
        power++;
    }
    // cout << "sum: " <<  sum << endl;
    // cout << "sumA: " << sumA << endl;
    ll sumB = sum - sumA;
    // cout << "sumB: " << sumB << endl;
    // cout << "log2(intital): " << (ll)log2(initial) << endl;
    sumB -= ((ll)log2(initial) + 1);
    // cout << "sumB later: " << sumB << endl;
    return sumB;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << (glr(r) - glr(l - 1)) << endl;
    }

    return 0;
}
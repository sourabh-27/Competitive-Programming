#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
#define pb push_back
#define mp make_pair
typedef long long int ll;

ll countDivisors(ll n) 
{ 
    ll cnt = 0; 
    for(ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
            else
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
 
int main()
{
    fast;
    ll n;
    cin >> n;
    cout << countDivisors(n) - 1 << endl;


    return 0;
}
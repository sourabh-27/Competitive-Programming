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
    ll count = 0;
    while(n != 0)
    {  
        count = count + (n & 1);
        n = n >> 1;
    }
    cout << count << endl;

    return 0;
}
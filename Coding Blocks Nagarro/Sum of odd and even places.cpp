#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    string s;
    cin >> s;
    ll len = s.length();
    ll odd = 0; ll even = 0;
    for(ll i = len - 1; i >= 0; i--)
    {
        if((len - i + 1) % 2 == 0)
        {
            even = even + s[i] - 48;
        }
        else
        {
            odd = odd + s[i] - 48;
        }
    }
    cout << even << endl;
    cout << odd << endl;

    return 0;
}
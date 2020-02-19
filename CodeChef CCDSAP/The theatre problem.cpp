#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;
 
int main()
{
    fast;
    //3 -> 2 people, 12 -> 1 people, 6 -> 1 people, 9 -> 2 people
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        int arr[6][6];
        for(ll i = 0; i <= 5; i++)
        {
            for(ll j = 0; j <= 5; j++)
            {
                arr[i][j] = 0;
            }
        }

        for(ll i = 0; i < n; i++)
        {
            char m; ll t;
            cin >> m >> t;
            t = t / 3; int con = m - 'A' + 1;
            arr[con][t] += 1;
        }

        
    }

    return 0;
}
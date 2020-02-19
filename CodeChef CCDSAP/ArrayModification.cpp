#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        ll temp = (k / n) % 3;
        ll temp2 = k % n;
        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for(ll i = 0; i < n / 2; i++)
        {
            while(temp--)
            {
                arr[i] = arr[i] ^ arr[n - i - 1];
                arr[n - i - 1] = arr[i] ^ arr[n - i - 1];
            }
            temp = (k / n) % 3;
        }
        for(ll i = 0; i < temp2; i++)
        {
            arr[i] = arr[i] ^ arr[n - i - 1];
        }
        if(n % 2 != 0 && k > n / 2)
        {
            arr[n / 2] = 0;
        }
        for(ll i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
/*3
7 11
5 6 11 7 2 9 10
10 9 2 0 11 6 5
6 9
5 6 11 2 9 10
10 9 2 11 6 5
14 30
23 56 2 3 6 7 34 67 23 78 98 25 13 67
23 56 25 98 78 23 67 97 16 72 97 27 53 84*/
}
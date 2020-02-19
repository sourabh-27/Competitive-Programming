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
    ll first = 1;
    ll second = 2;
    ll temp;
    ll arr[31];
    arr[1] = 1;
    arr[2] = 2;
    for(ll i = 3; i <= 30; i++)
    {
        arr[i] = first + second;
        // cout << arr[i] << endl;
        temp = first;
        first = second;
        second = temp + first;
    }
    while(t--)
    {
        ll n;
        cin >> n;
        cout << arr[n] << " ";
    }

    return 0;
}
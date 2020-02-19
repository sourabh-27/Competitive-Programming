#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, t;
    cin >> n >> t;
    ll arr[n + 1];
    for(ll i = 1; i < n; i++)
    {
        cin >> arr[i];
    }

    ll temp = 1; int flag = 0;
    for(ll i = 1; i < n; i++)
    {
        temp += arr[i];
        i = i + arr[i] - 1;
        if(temp == t)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


    return 0;
}
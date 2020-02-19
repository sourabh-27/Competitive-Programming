#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n + 1];
    ll evenCount = 0;
    ll oddCount = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }

    if(abs(oddCount - evenCount) == 0 || abs(oddCount - evenCount) == 1)
    {
        cout << "DL" << endl;
    }
    else
    {
        cout << "DETAIN" << endl;
    }


    return 0;
}
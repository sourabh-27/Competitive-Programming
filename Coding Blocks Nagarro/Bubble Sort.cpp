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
    long long arr[n + 1];
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    ll flag = 0; ll count = 0;
    for(ll i = 0; i < n - 1; i++)
    {
        for(ll j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                flag = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if(flag == 0){
            break;
        }
        flag = 0;
        count++;
    }
    cout << "Times: " << count << endl;
    for(ll i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
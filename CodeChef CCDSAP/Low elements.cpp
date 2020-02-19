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
    long long arr[n + 1];
    ll count = 1;
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll mini = arr[0];
    for(ll i = 1; i < n; i++)
    {
        if(arr[i] < mini)
        {
            count++;
            mini = arr[i];
        }
    }
    cout << count << endl;


    return 0;
}
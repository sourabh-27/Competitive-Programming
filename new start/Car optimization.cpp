#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int l, m, s;
    cin >> l >> m >> s;
    int ser[n]; int arr[n]; int dep[n]; string size[n]; int diff[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ser[i] >> size[i] >> arr[i] >> dep[i];
        diff[i] = dep[i] - arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        
    }

    return 0;
}
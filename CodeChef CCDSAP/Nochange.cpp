#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n" 
typedef long long int ll;

bool findway(long long * arr, ll n, ll p, bool * visited, long long (&arr3)[100000])
{
    if(p == 0)
    {
        return false;
    }
    if(p < 0)
    {
        return true;
    }

    for(long long i = n - 1; i >= 0; i--)
    {
        // cout << "The current value of p is: " << p << " and I am substracting: " << arr[i] << endl;
        if(findway(arr, n, p - arr[i], visited, arr3) && !visited[i])
        {
            // cout << "Value of i: " << i << endl;
            arr3[i] = arr3[i] + 1;
            // cout << arr3[i] << " arr2[i]" << endl;
            return true;
        }
        else
        {
            // cout << "YO"  << endl;
            arr3[i] = arr3[i] - 1;
            visited[i] = true;
        }
    }
    return false;
}
 
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, p;
        cin >> n >> p;
        long long *arr = new long long[n + 1];
        for(ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long * arr2 = new long long[n + 1];
        for(ll i = 0; i <= n; i++)
        {
            arr2[i] = 0;
        }

        bool * visited = new bool[n + 1];
        memset(visited, false, sizeof(visited));

        long long arr3[100000] = {0};

        bool ans = findway(arr, n, p, visited, arr3);
        if(!ans)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for(ll i = 0; i < n; i++)
            {
                cout << arr3[i] << " ";
            }
        }
    }
    
    return 0;
}
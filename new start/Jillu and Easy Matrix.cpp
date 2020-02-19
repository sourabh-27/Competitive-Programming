#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

void rotateL(ll ** a, ll n)
{
    for (int x=0;x<n/2;x++) 
    {
        for (int y=x;y<n-x-1;y++) 
        { 
            int temp=a[x][y];
            a[x][y]=a[y][n-1-x];
            a[y][n-1-x]=a[n-1-x][n-1-y];
            a[n-1-x][n-1-y]=a[n-1-y][x];
            a[n-1-y][x]=temp; 
        } 
    }
    return;
}

void rotateR(ll ** arr, ll n)
{
    for(ll i = 0; i < n / 2; i++)
    {
        for(ll j = i; j < n - i - 1; j++)
        {
            ll x = arr[i][j]; 
            arr[i][j] = arr[n - 1 - j][i]; 
            arr[n - 1 - j][i] = arr[n - 1 - i][n - 1 - j]; 
            arr[n - 1 - i][n - 1 - j] = arr[j][n - 1 - i]; 
            arr[j][n - 1 - i] = x;
        }
    }
    return;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, q;
        cin >> n >> q;
        ll ** arr= new ll*[n];
        for(ll i = 0; i < n; i++)
        {
            arr[i] = new ll[n];
        }
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        for(int j = 0; j < q; j++)
        {
            char c; ll x;
            cin >> c >> x;
            // cout << x << endl;
            if(c == 'L')
            {
                // cout << "x: " << x << endl;
                for(ll i = 0; i < x; i++)
                {
                    rotateL(arr, n);
                }
            }
            else
            {
                // cout << "x: " << x << endl;
                for(ll i = 0; i < x; i++)
                {
                    rotateR(arr, n);
                }
            } 
            for(ll i = 0; i < n; i++)
            {
                for(ll j = 0 ; j < n; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            // cout << endl;
        }
    }

    return 0;
}
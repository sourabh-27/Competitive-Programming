#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n], arr2[n];
        int arr3[n]; int k;
        for(int i = 0; i < n; i++)
        {
            cin >> k;
            arr[i] = k * 20;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> k;
            arr2[i] = k * 10;
        }

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            k = arr[i] - arr2[i];
            if(k < 0)
            {
                arr3[i] = 0;
            }
            else
            {
                arr3[i] = k;
            }
            maxi = max(arr3[i], maxi);
        }

        cout << maxi << endl;
    }

    return 0;
}
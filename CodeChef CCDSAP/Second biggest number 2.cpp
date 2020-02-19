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
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool x = next_permutation(arr, arr + n);
        if(x)
        {
            for(int i = 0; i < n; i++)
            {
                cout << arr[i];
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }

    return 0;
}
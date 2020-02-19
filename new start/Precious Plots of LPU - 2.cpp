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
        int n, m;
        cin >> n >> m;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int arr2[m];
        for(int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        vector<int> vec;
        int flag = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i] == arr2[j])
                {
                    flag = 1;
                }
            }
            if(flag == 0)
            {
                cout << arr[i] << " ";
            }
            flag = 0;
        }

        for(int i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
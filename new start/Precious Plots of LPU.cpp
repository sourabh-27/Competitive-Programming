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
        bool * visited = new bool[n];
        for(int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        int arr3[n];
        for(int i = 0; i < m; i++)
        {
            int k;
            cin >> k;
            arr3[i] = k;
            visited[k] = true;
        }

        cout << "yo";
        for(int i = 0; i < n; i++)
        {
            cout << visited[i] << " ";
        }
        cout << endl;

        int arr2[n];
        for(int i = 0; i < n; i++)
        {
            if(visited[arr[i]])
            {
                arr2[i] = arr[i];
            }
        }

        for(int i = 0; i < m; i++)
        {
            arr2[i] = arr3[i];
        }

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
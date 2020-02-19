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
    int arr[n], arr2[n];
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = x; arr2[i] = y;
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == arr2[j])
            {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}